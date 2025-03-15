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
    法1：dfs + 记忆化
        dfs(, k)
    法2：dp
        
    */
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        std::function<int(int, int)> dfs = [&](int idx, int k) {
            
            if (n - idx < k)
                return 0;
            if (n - idx == k) {
                return std::accumulate(arr.begin() + idx, arr.end(), 0);
            }
            if (k == 1) {
                int group_max = *std::max_element(arr.begin() + idx, arr.end());
                return group_max * (n - idx);
            }
            int group_max = INT_MIN;
            int group_sum = 0;
            int max_sum = 0;
            for (int i=idx; i<n; ++i) {
                group_max = max(group_max, arr[i]);
                group_sum = group_max * (idx - i + 1);
                max_sum = max(max_sum, group_sum + dfs(i+1, k-1));
            }
            return max_sum;
        };
        return dfs(0, k);
    }
};

int main()
{
    Solution solution;

    auto start = std::chrono::high_resolution_clock::now();

    vector<vector<int>> grid = {{9,5,7,3},
                                {8,9,6,1},
                                {6,7,14,3},
                                {2,5,3,1}};

    int ans = solution.maxScore(grid);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::micro> elapsed_time = end - start;

    cout << "ans:" << ans << ", time:" << (elapsed_time.count() / 1000) << "ms" << endl;
    return 0;
}
