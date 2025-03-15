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
    // 记忆化搜素，map，upper_bound
    // 遍历一次nums，得出所有特殊数组的范围，写入map，然后遍历queries
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        if (nums.size() == 1)
            return vector<bool>(queries.size(), true);
        vector<bool> res(queries.size());
        map<int, int> special_range; // begin - end
        int begin = 0;
        bool pre = nums[0] % 2;
        for (int i=1; i<nums.size(); ++i) {
            bool cur = nums[i] % 2;
            if (cur != pre) {
                pre = cur;
            }
            else {
                special_range[begin] = i-1;
                pre = cur;
                begin = i;
            }
        }
        special_range[begin] = nums.size() - 1;
        for (auto it : special_range) {
            cout << it.first << "," << it.second << endl;
        }

        for (int i = 0; i<queries.size(); ++i) {
            int start = queries[i][0];
            int end = queries[i][1];
            auto it = special_range.upper_bound(start);
            if (it != special_range.begin()) {
                it = prev(it);
                if (it->first <= start && it->second >= end) {
                    res[i] = true;
                }
            }
            else {
                res[i] = false;
            }
        }
        return res;
    }
};

int main()
{
    Solution solution;

    auto start = std::chrono::high_resolution_clock::now();
    // vector<int> nums = {4,3,1,6};
    // vector<vector<int>> queries({{0,2}, {2,3}});
    vector<int> nums = {2,2};
    vector<vector<int>> queries({{0,0}});
    vector<bool> ans_vec = solution.isArraySpecial(nums, queries);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::micro> elapsed_time = end - start;

    std::stringstream ss;
    for (bool ans : ans_vec) {
        ss << ans << ",";
    }

    cout << "ans:" << ss.str() << ", time:" << (elapsed_time.count() / 1000) << "ms" << endl;


    return 0;
}
