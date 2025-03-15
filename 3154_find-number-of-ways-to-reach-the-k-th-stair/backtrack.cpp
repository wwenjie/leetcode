#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cmath>     // 包含 pow
#include <functional>
#include <algorithm>// 包含 std::sort
#include <limits.h> // 包含 INT_MAX
#include <chrono>
#include <numeric>  // 包含 std::accumulate
#include "../util/util.h"

using namespace std;
      class Solution {
public:
    /*
    法1：动态规划（还有倒退的情况，好像不能用dp）
    3维dp，其中一维表示能不能往下走
    定义：
        dp[i][jump][m] 表示当前处于第i台阶，m表示已经使用往下走
    状态转移：
        dp[i][jump][1] = dp[i+1][jump][0]
        dp[i][jump][0] = dp[i-2^jump][jump-1][0] + dp[i-2^jump][jump-1][1]
    
    法2：回溯法 + 记忆化搜索
        好像回溯法更好，因为dp中有一些jump的情况是不存在的
    */
    int waysToReachStair1(int k) {
        double max_jump_double = std::log(k) / std::log(2);
        int max_jump = std::ceil(max_jump_double);
        vector<vector<vector<int>>> dp(k+2, vector<vector<int>>(max_jump+1, vector<int>(2)));
        
        dp[0][0][0] = 1;
        dp[0][0][1] = 1;
        for (int i=0; i<=k+1; ++i) {
            for (int j=0;j<=max_jump;++j) {
                dp[i][j][1] = dp[i+1][j][0];
                dp[i][j][0] = dp[i-pow(2,j)][j-1][0] + dp[i-pow(2,j)][j-1][1];
            }
        }
        int res = 0;
        
        return res;
    }

    /*
    法2：回溯 + 记忆化搜索
    用vector记忆化会超时，
    像标案那样改用状态压缩后的map做记忆化就好了
    */
    int waysToReachStair(int k) {
        //vector<vector<vector<int>>> memo(k+2, vector<vector<int>>(k+2, vector<int>(2, -1)));
        // 将(i,jump,down)状态压缩为一个uint64_t
        unordered_map<uint64_t, int> memo;

        std::function<int(int,int,bool)> dfs = [&](int cur, int jump, bool down) {
            if (cur > k+1 || jump > k+1) {
                return 0;
            }
            // if (memo[cur][jump][down] > 0) {
            //     return memo[cur][jump][down];
            // }
            uint64_t mask = (uint64_t)cur << 32 | jump << 1 | down;
            if (memo.count(mask)) {
                return memo[mask];
            }
            int res = 0;
            // if (cur == k || (cur == k+1 && down == false)) {
            if (cur == k) {
                res += 1;
            }
            
            if (down == false) {
                res += dfs(cur-1, jump, true);
            }
            res += dfs(cur + (1 << jump), jump+1, false);
            // res += dfs(cur + pow(2, jump), jump+1, false);
            // memo[cur][jump][down] = res;
            memo[mask] = res;
            return res;
        };
        return dfs(1, 0, false);
    }
};

int main()
{
    Solution solution;

    auto start = std::chrono::high_resolution_clock::now();

    int ans = solution.waysToReachStair(1);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::micro> elapsed_time = end - start;

    cout << "ans:" << ans << ", time:" << (elapsed_time.count() / 1000) << "ms" << endl;
    return 0;
}
