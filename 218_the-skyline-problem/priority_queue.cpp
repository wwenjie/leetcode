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
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        // std::function<bool(pair<int,int>, pair<int,int>)> cmp = ...
        auto cmp = [](pair<int,int>& a, pair<int,int>& b) -> bool {
            return a.second < b.second;
        };
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> que(cmp);

        vector<int> boundaries;
        for (vector<int>& building : buildings) {
            boundaries.emplace_back(building[0]);
            boundaries.emplace_back(building[1]);
        }
        cout << "111111" << endl;
        std::sort(boundaries.begin(), boundaries.end());
        cout << "222222" << endl;
       
        vector<vector<int>> ans;
        int n = buildings.size();
        int idx = 0;
        for (int x: boundaries) {
            cout << "3------->> " << endl;
            while (idx < n && buildings[idx][0] <= x) {
                que.emplace(buildings[idx][1], buildings[idx][2]);
                idx++;
            }
            cout << "4------->> " << endl;
            while (!que.empty() && que.top().first <= x) {
                que.pop();
            }
            cout << "5------->> " << endl;

            int max_y = que.empty() ? 0 : que.top().second;
            if (ans.size() == 0 || ans.back()[1] != max_y) {
                ans.push_back({x, max_y});
            }
            cout << "6------->> " << endl;
        }
        return ans;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> buildings = {{2,9,10},{3,7,15},{5,12,12},{15,20,10},{19,24,8}};
    auto start = std::chrono::high_resolution_clock::now();
    vector<vector<int>> ans = solution.getSkyline(buildings);
    auto end = std::chrono::high_resolution_clock::now();

    std::stringstream ss;

    for (vector<int> p : ans) {
        ss << "(" << p[0] << "," << p[1] << "), ";
    }

    std::chrono::duration<double, std::micro> elapsed_time = end - start;
    cout << "ans:" << ss.str() << ", time:" << (elapsed_time.count() / 1000) << "ms" << endl;

    return 0;
}
