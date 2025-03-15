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
#include "../util/util.h"

using namespace std;

// 法2，差分数组，时间O(n^2)
class MyCalendarTwo {
public:
    MyCalendarTwo() {
    }
    
    bool book(int start, int end) {
        int book_cnt = 0;
        ++mp[start];
        --mp[end];
        for (auto& it : mp) {
            book_cnt += it.second;
            if (book_cnt > 2) {
                --mp[start];
                ++mp[end];
                return false;
            }
        }
        return true;
    }
private:
    map<int,int> mp;
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */

int main()
{
    // Solution solution;
    // // vector<int> nums = {4,2,1,4,3,4,5,8,15};
    // vector<int> nums = {7,4,5,1,8,12,4,7};

    // auto start = std::chrono::high_resolution_clock::now();
    // int ans = solution.lengthOfLIS(nums, 5);
    // auto end = std::chrono::high_resolution_clock::now();

    // std::chrono::duration<double, std::micro> elapsed_time = end - start;
    // cout << "ans:" << ans << ", time:" << (elapsed_time.count() / 1000) << "ms" << endl;

    MyCalendarTwo* obj = new MyCalendarTwo();
    bool ans = obj->book(10, 20);
    cout << "ans: " << ans << endl;
    ans = obj->book(10, 40);
    cout << "ans: " << ans << endl;

    // int val = obj->query(5,15);
    // cout << "val: " << val << endl;
    // val = obj->query(10,11);
    // cout << "val: " << val << endl;
    // ans = obj->book(15, 25);
    // cout << "ans: " << ans << endl;

    return 0;
}





