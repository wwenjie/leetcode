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
    min[i][j] 表示行<=i和列<=j的最小值
    max[i][j] 表示行<=i和列<=j的最大值
    dp[i][j] = max[i][j] - min[i][j]
    */
    int maxScore(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> min_grid(m, vector<int>(n, grid[0][0]));
        // vector<vector<int>> max_grid(m, vector<int>(n, grid[0][0]));
        vector<vector<int>> dp(m, vector<int>(n, INT_MIN));
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (i-1 >= 0) {
                    dp[i][j] = max(dp[i-1][j], grid[i][j] - min_grid[i-1][j]);
                    min_grid[i][j] = min(min_grid[i-1][j], grid[i][j]);
                }
                if (j-1 >= 0) {
                    dp[i][j] = max(dp[i][j], dp[i][j-1]);
                    dp[i][j] = max(dp[i][j], grid[i][j] - min_grid[i][j-1]);
                    min_grid[i][j] = min(min_grid[i][j], grid[i][j]);
                    min_grid[i][j] = min(min_grid[i][j], min_grid[i][j-1]);
                }
            }
        }
        print_vector2(min_grid);
        print_vector2(dp);
        return dp[m-1][n-1];
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
