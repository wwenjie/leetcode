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
    // 自写法1：桶排序，时间O(n)，空间O(n)，空间不满足O(1)
    // 跟标案思路差不多，但是O(n)优化成O(1)，要原地修改nums
    int firstMissingPositive_1(vector<int>& nums) {
        int n = nums.size();
        vector<bool> bucket(n+1);
        for (int num : nums) {
            if (1 <= num && num <= n)
            bucket[num] = true;
        }
        for (int i=1; i<=n; ++i) {
            if (!bucket[i])
                return i;
        }
        return n+1;
    }

    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        // 去掉全部负数
        for (int i=0; i<n; ++i) {
            if (nums[i] <= 0) {
                nums[i] = n+1;
            }
        }
        print_vector(nums);
        // [3,4,5,1]
        // 原地在nums里打标记，如果num属于[1,n]，就给下标=num-1加一个负号
        for (int i=0; i<n; ++i) {
            int num = abs(nums[i]);
            if (num <= n && nums[num-1] > 0) {
                nums[num-1] = -nums[num-1];
            }
        }
        print_vector(nums);
        // [-3,4,-5,-1]
        for (int i=0; i<n; ++i) {
            if (nums[i] > 0) 
                return i+1;
        }
        return n+1;
    }

};

int main()
{
    Solution solution;

    auto start = std::chrono::high_resolution_clock::now();

    // vector<int> nums = {3,4,-1,1};
    vector<int> nums = {1,1};

    int ans = solution.firstMissingPositive(nums);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::micro> elapsed_time = end - start;

    cout << "ans:" << ans << ", time:" << (elapsed_time.count() / 1000) << "ms" << endl;
    return 0;
}
