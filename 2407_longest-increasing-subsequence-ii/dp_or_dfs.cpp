#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <functional>
#include <algorithm>// 包含 std::sort
#include <limits.h> // 包含 INT_MAX
#include <chrono>
#include <numeric> // 包含 std::accumulate
#include "../util/util.h"

using namespace std;

class Solution {
public:
    /*
    法1：动态规划 O(n^3) 超时
    dp[x][z] 表示x~z之间开始，z结束的字符串，而不是x找到z之间y字符结束的情况下的最大子串
    dp[x][z] = max(dp[x][z], dp[x][y] + 1), if nums[z] - nums[y] > k
    */
    int lengthOfLIS_1(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 1));
        // for (int i=0; i<n; ++i) {
        //     dp[i][i] = 1;
        // }
        for (int x=0; x<n-1; ++x) {
            for (int z=x+1; z<n; ++z) {
                for (int y=x; y<z; ++y) {
                    // dp[x][z] = max(dp[x][z], dp[x][y]); // 只能是z结束，而不能是y结束的子串
                    if (nums[z] > nums[y] && nums[z] - nums[y] <= k)
                        dp[x][z] = max(dp[x][z], dp[x][y] + 1);
                }
            }
        }
        int res = 0;
        for (int i=0; i<n; ++i) {
            res = max(res, dp[0][i]);
        }
        return res;
    }

    /*
    法2 dp，O(n^2)，法1的基础上优化得到，超时
    dp[r] 表示r下标结束的子串的最大长度
    dp[r] = max(dp[r], dp[r-l]), if nums[r] > nums[l]
    */
    int lengthOfLIS(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n, 1);
        
        for (int r=0; r<n; ++r) {
            for (int l=0; l<r; ++l) {
                if (nums[r] > nums[l] && nums[r] - nums[l] <= k)
                    dp[r] = max(dp[r], dp[l] + 1);
            }
        }
        int res = 0;
        for (int i=0; i<n; ++i) {
            res = max(res, dp[i]);
        }
        return res;
    }

    /*
    法3：dfs + 记忆化搜索，时间O(n^2)，dfs时间O(n)，递归深度最大为n，总体应该是O(n^2)，超时
    */
    int lengthOfLIS_3(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,int> memo;
        std::function<int(int)> dfs = [&](int last) {
            if (memo.count(last)) {
                return memo[last];
            }
            int max_len = 0;
            for (int i=last+1; i<n; ++i) {
                if (nums[last] < nums[i] && nums[i] - nums[last] <= k) {
                    max_len = max(max_len, dfs(i) + 1);
                }
            }
            memo[last] = max_len;
            return max_len;
        };
        int ans = 1;
        for (int i=0; i<n; ++i) {
            ans = max(ans, dfs(i) + 1);
        }
        return ans;
    }

};

int main()
{
    Solution solution;
    // vector<int> nums = {4,2,1,4,3,4,5,8,15};
    vector<int> nums = {7,4,5,1,8,12,4,7};

    auto start = std::chrono::high_resolution_clock::now();
    int ans = solution.lengthOfLIS(nums, 5);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::micro> elapsed_time = end - start;
    cout << "ans:" << ans << ", time:" << (elapsed_time.count() / 1000) << "ms" << endl;

    return 0;
}
