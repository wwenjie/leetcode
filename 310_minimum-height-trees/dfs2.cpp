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
#include <functional>
#include <algorithm>// 包含 std::sort
#include <limits.h> // 包含 INT_MAX
#include <chrono>
#include <numeric> // 包含 std::accumulate
using namespace std;

class Solution {
public:
    // 法1：自写，每个节点求深度，O(n^2)
    vector<int> findMinHeightTrees1(int n, vector<vector<int>>& edges) {
        map<int,vector<int>> edge_map;
        for (vector<int>& edge : edges) {
            edge_map[edge[0]].push_back(edge[1]);
            edge_map[edge[1]].push_back(edge[0]);
        }

        map<pair<int,int>,int> memo;
        std::function<int(int, int)> dfs = [&](int pre, int cur) {
            if (memo.count(make_pair(pre, cur))) {
                return memo[make_pair(pre, cur)];
            }
            int max_depth = 0;
            for (int next : edge_map[cur]) {
                if (next == pre)
                    continue;
                max_depth = max(max_depth, dfs(cur, next) + 1);
            }
            memo[make_pair(pre,cur)] = max_depth;
            return max_depth;
        };
        int min_depth = INT_MAX;
        vector<int> res;
        for (int i=0; i<n; ++i) {
            int depth = dfs(-1, i);
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

    // 求出2个最远的节点，然后广度优先搜索(层序遍历)，中间的节点就是答案
    // 随机用一个入度为1的节点开始遍历，找到深度最深的点，然后再相向bfs
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        map<int,vector<int>> edge_map;
        for (vector<int>& edge : edges) {
            edge_map[edge[0]].push_back(edge[1]);
            edge_map[edge[1]].push_back(edge[0]);
        }

        std::function<void(int, int&, vector<int>& parent)> bfsGetDeepestNodeAndPath = [&](int root, int& deepest_node, vector<int>& parent) {
            std::queue<int> que;
            std::vector<bool> visited(n, false);
            que.push(root);
            while(!que.empty()) {
                int cnt = que.size();
                int node;
                for (int i=0; i<cnt; ++i) {
                    node = que.front();
                    visited[node] = true;
                    que.pop();
                    for (int child : edge_map[node]) {
                        if (!visited[child]) {
                            que.push(child);
                            parent[child] = node;
                            cout << "child:" << child << ", parent:" <<node << endl;
                        }
                    }
                }
                if (que.empty()) {
                    deepest_node = node;
                }
            }
        };
        cout << "1---->>>" << endl;
        int x_node = -1;
        vector<int> parent(n, -1);
        
        bfsGetDeepestNodeAndPath(1, x_node, parent);
        std::stringstream ss1;
        for (int i=0;i<n;++i) {
            ss1 << parent[i] << ",";
        }
        std::fill(parent.begin(), parent.end(), -1);
        
        cout << "2---->>>" << ss1.str() << endl;

        int y_node = -1;
        bfsGetDeepestNodeAndPath(x_node, y_node, parent);

        std::stringstream ss;
        for (int i=0;i<n;++i) {
            ss << parent[i] << ",";
        }
        cout << "3---->>> " << x_node << "," << y_node << " , " << ss.str() << endl;

        // 获取y_node到x_node的路径，类似并查集的做法
        vector<int> path;
        while(y_node != -1) {
            path.push_back(y_node);
            y_node = parent[y_node];
        }
        cout << "4---->>>" << endl;


        // 查找deepest_node1和deepest_node2的中点
        int m = path.size();
        if (m % 2 == 0)
            return {path[m/2-1], path[m/2]};
        else
            return {path[m/2]};
    }
};

int main()
{
    Solution solution;
    //vector<vector<int>> edges = {{1,0},{1,2},{1,3}};
    vector<vector<int>> edges = {{0,1},{0,2},{0,3},{3,4},{4,5}};
    
    auto start = std::chrono::high_resolution_clock::now();
    vector<int> ans = solution.findMinHeightTrees(6, edges);
    auto end = std::chrono::high_resolution_clock::now();

    std::stringstream ss;
    for (int i : ans) {
        ss << i << ",";
    }

    std::chrono::duration<double, std::micro> elapsed_time = end - start;
    cout << "ans:" << ss.str() << ", time:" << (elapsed_time.count() / 1000) << "ms" << endl;

    return 0;
}
