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
    // 法1：回溯
    // 每一位可以加入到上个分组，也可以加入到下个分组
    int minimumValueSum(vector<int>& nums, vector<int>& andValues) {
        int res = INT_MAX;
        int n = nums.size();
        int m = andValues.size();
        vector<int> group_last_idx(m, -1);     // 每个分组最后一个值的下标
        vector<int> group_and_res(m, INT_MAX); // 按照group_state的划分，每个分组and的结果
        unordered_set<string> memo;
        int begin=0;
        std::function<void(int, int, int)> dfs = [&](int cur_group, int cur_idx, int cur_sum) {
            if (cur_idx == n && cur_group == m) {
                int sum = 0;
                for (int i=0; i<group_last_idx.size(); ++i) {
                    sum += nums[group_last_idx[i]];
                }
                res = min(res, sum);
                cout << "1a---->> " << sum << "," << vector2str(group_last_idx) << endl;;
                cout << "1b---->>" << sum << "," << vector2str(group_and_res) << endl;
                return;
            }
            else if (cur_idx >= n || cur_group >= m || n-cur_idx < m-cur_group)
                return;
            else if (cur_sum >= res)
                return;
            string memo_key;
            for (int idx : group_last_idx)
                memo_key += to_string(idx) + ",";
            if (memo.count(memo_key)) {
                cout << "memo cout ---->> " << memo_key << endl;
                return;
            }
            memo.insert(memo_key);
            int new_and_res = group_and_res[cur_group];
            cout << "111----->>" << endl;
            for (int i=cur_idx; (i<n) && (n-i >= m-cur_group); ++i) {
                new_and_res = new_and_res & nums[i];
                if (new_and_res < andValues[cur_group] 
                    || __builtin_popcount(new_and_res) < __builtin_popcount(andValues[cur_group]))
                    return;
                if (new_and_res == andValues[cur_group]) {
                    int old_last_idx = group_last_idx[cur_group];
                    int old_and_res = group_and_res[cur_group];

                    group_last_idx[cur_group] = i;
                    group_and_res[cur_group] = new_and_res;

                    // string memo_key1;
                    // for (int idx : group_last_idx)
                    //     memo_key1 += to_string(idx) + ",";
                    // memo.insert(memo_key1);
                    dfs(cur_group+1, i+1, cur_sum+nums[i]);
                    // 剪枝
                    group_last_idx[cur_group] = old_last_idx;
                    group_and_res[cur_group] = old_and_res;
                    cout << "222----->>" << i << endl;
                }
                cout << "333----->>" << i << endl;
            }
        };
        dfs(0, 0, 0);
        return res == INT_MAX ? -1 : res;
    }
};

int main()
{
    Solution solution;

    auto start = std::chrono::high_resolution_clock::now();
    // vector<int> nums = {4,3,1,6};
    // vector<vector<int>> queries({{0,2}, {2,3}});
    // vector<int> nums = {1,4,3,3,2};
    // vector<int> andValues({0,3,3,2});
    // vector<int> nums = {4,8,2,9};
    // vector<int> andValues({0,0});
    vector<int> nums = {3,1};
    vector<int> andValues({3,1});
    int ans = solution.minimumValueSum(nums, andValues);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::micro> elapsed_time = end - start;

    cout << "ans:" << ans << ", time:" << (elapsed_time.count() / 1000) << "ms" << endl;


    return 0;
}
