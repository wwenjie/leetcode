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
    10 20
    2,17,18,19
    */
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
        sort(buses.begin(), buses.end());
        sort(passengers.begin(), passengers.end());

        int m = buses.size();
        int n = passengers.size();

        // 1 模拟乘客上车
        int j = 0, cap;
        for (int bus_time: buses) {
            for (cap = capacity; cap > 0 && j < n && passengers[j] <= bus_time; cap--) {
                j++;
                cout << "1----->>> j:" << j << ",cap:" << cap << endl;
            }
            cout << "bus_time:" << bus_time << ",cap:" << cap << endl;
        }

        cout << "2------>> j:" << j << ",cap:" << cap << endl;

        // 2 寻找插队时机
        // --后，j是最后一个上车的乘客
        j--;
        // 2.1 若最后一辆车还有位置，ans从buses.back()开始往前找
        // 2.2 若没位置，ans从最后一个乘客开始往前找位置插队
        int ans = (cap > 0 ? buses.back() : passengers[j]);
        while (j >= 0 && ans == passengers[j]) {
            // 插队最后一个乘客，往前找没人到达的时刻
            ans--;
            j--;
        }
        return ans;      
        
    }
};

int main()
{
    Solution solution;

    auto start = std::chrono::high_resolution_clock::now();

    vector<int> buses = {10,20};
    vector<int> passengers = {2,17,18,19};
    int capacity = 2;
    int ans = solution.latestTimeCatchTheBus(buses, passengers, capacity);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::micro> elapsed_time = end - start;

    cout << "ans:" << ans << ", time:" << (elapsed_time.count() / 1000) << "ms" << endl;

    return 0;
}
