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
using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        map<int,vector<int>> edge_map;
        for (vector<int>& edge : edges) {
            edge_map[edge[0]].push_back(edge[1]);
            edge_map[edge[1]].push_back(edge[0]);
        }
        
        std::function<int(int, int)> dfs = [&](int pre, int cur) {
            int max_depth = 0;
            for (int next : edge_map[cur]) {
                if (next == pre)
                    continue;
                max_depth = max(max_depth, dfs(cur, next) + 1);
            }
            return max_depth;
        };
        int min_depth = INT_MAX;
        vector<int> res;
        for (int i=0; i<n; ++i) {
            int depth = dfs(-1, i);
            cout<< "--->>> " << i << ", " << depth << endl;
            if (depth == min_depth) {
                res.push_back(i);
            }
            else if (depth > min_depth) {
                continue;
            }
            else {
                min_depth = depth;
                res.clear();
                res.push_back(i);
            }
        }
        return res;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> edges = {{1,0},{1,2},{1,3}};
    auto start = std::chrono::high_resolution_clock::now();
    vector<int> ans = solution.findMinHeightTrees(4, edges);
    auto end = std::chrono::high_resolution_clock::now();

    std::stringstream ss;
    for (int i : ans) {
        ss << i << ",";
    }

    std::chrono::duration<double, std::micro> elapsed_time = end - start;
    cout << "ans:" << ss.str() << ", time:" << (elapsed_time.count() / 1000) << "ms" << endl;

    return 0;
}
