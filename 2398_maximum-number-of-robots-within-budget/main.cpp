#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
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
    法1：dp 0-1背包问题，选或不选
        dp[i][j]前i个机器人产生开销为j时，最多运行的机器人数
        dp[i][j] = max(dp[i-1][j], dp[i-1][j-])
        max
    法2：dfs递归，好像不行
    法3：贪心
    法4：标案：滑动窗口+单调队列
    */
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        int n = chargeTimes.size();
        int k = 0;
        long long cost = 0;
        long long total_cost = 0;
        deque<int> que; // 已选取物品的charge下标，单调递减
        
        int l = 0, r = 0;
        while(r < n) {
            // 入
            while(!que.empty() && chargeTimes[que.back()] <= chargeTimes[r]) {
                que.pop_back();
            }
            que.push_back(r);
            cost += runningCosts[r];
            long long total = chargeTimes[que.front()] + (r-l+1) * cost;

            // 出
            if (total > budget) {
                // 超过预算，把l下标的去掉
                while (l <= r) {
                    while(!que.empty() && que.front() <= l) {
                        que.pop_front();
                    }
                    cost -= runningCosts[l];
                    if (!que.empty())
                        total = chargeTimes[que.front()] + (r-l) * cost;
                    else
                        total = 0;
                    cout << "l:" << l << ",r:" << r << ",total:" << total << endl;

                    l++;

                    if (total <= budget) {
                        break;
                    }
                }
            }
            k = max(k, r-l+1);
            r++;
        }
        return k;
    }
};


int main()
{
    Solution solution;

    auto start = std::chrono::high_resolution_clock::now();

    vector<int> charge = {11,12,19};
    vector<int> cost = {10,8,7};
    int budget = 19;
    // vector<int> charge = {3,6,1,3,4};
    // vector<int> cost = {2,1,3,4,5};
    // int budget = 25;
    int ans = solution.maximumRobots(charge, cost, budget);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::micro> elapsed_time = end - start;

    cout << "ans:" << ans << ", time:" << (elapsed_time.count() / 1000) << "ms" << endl;
    return 0;
}
