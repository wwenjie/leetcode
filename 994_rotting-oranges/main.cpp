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
    // 法1：按逻辑模拟
    // 法2：从每个节点开始bfs、层序遍历
    int orangesRotting(vector<vector<int>>& grid) {
        int minute = 0; // 如果出现0/1的孤岛，就返回-1
        bool change = true;
        int m = grid.size();
        int n = grid[0].size();
        bool all_rotting = true;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (grid[i][j] == 1)
                    all_rotting = false;
            }
        }
        if (all_rotting)
            return 0;
        vector<vector<int>> new_grid = grid;
        while(change) {
            all_rotting = true;
            change = false;
            for (int i=0; i<m; ++i) {
                for (int j=0; j<n; ++j) {
                    if (grid[i][j] != 1)
                        continue;
                    if ((i-1>=0 && grid[i-1][j] == 2)
                        || (j-1>=0 && grid[i][j-1] == 2)
                        || (j+1<n && grid[i][j+1] == 2)
                        || (i+1<m && grid[i+1][j] == 2)) {
                        new_grid[i][j] = 2;
                        change = true;
                    }
                    if (new_grid[i][j] == 1)
                        all_rotting = false;
                }
            }
            minute++;
            cout << "minute:" << minute << ",change:" << change << ",all_rotting:" << all_rotting << endl;
            print_vector2(new_grid);
            if (all_rotting)
                return minute;
            grid = new_grid;
        }
        return -1;
    }
};


int main()
{
    Solution solution;

    auto start = std::chrono::high_resolution_clock::now();

    // vector<int> nums = {3,4,-1,1};
    vector<vector<int>> grid = {{2,1,1}, {1,1,0}, {0,1,1}};

    int ans = solution.orangesRotting(grid);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::micro> elapsed_time = end - start;

    cout << "ans:" << ans << ", time:" << (elapsed_time.count() / 1000) << "ms" << endl;
    return 0;
}
