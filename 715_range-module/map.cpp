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


// 法2： map + upper_bound + prev(it) 解法
class RangeModule_2 {
private:
    map<int,int> _map;
public:
    RangeModule_2() { }
    
    void addRange(int left, int right) {
        auto it = _map.upper_bound(left);
        if (it != _map.begin()) {
            // it既不是第一元素，也非空
            auto pre_it = prev(it);
            if (pre_it->second >= right) {
                // 前面的区间覆盖了left~right
                return;
            }
            if (pre_it->second >= left) {
                // 前面的区间在left~right间结束
                left = pre_it->first;
                _map.erase(pre_it);
            }
        }
        while (it != _map.end() && it->first <= right) {
            // 把left~right间的区间删除
            right = max(right, it->second);
            it = _map.erase(it);
        }
        _map[left] = right;
    }
    
    bool queryRange(int left, int right) {
        auto it = _map.upper_bound(left);
        if (it == _map.begin()) {
            return false;
        }
        it = prev(it);
        return right <= it->second;
    }
    
    void removeRange(int left, int right) {
        auto it = _map.upper_bound(left);
        // it == _map.begin() 则表示 it可能为空，或it为第一个元素
        if (it != _map.begin()) {
            auto pre_it = prev(it);
            if (pre_it->second >= right) {
                // 前一个区间包含了left~right
                int old_right = pre_it->second;
                if (left == pre_it->first) {
                    // 前一个区间，就是从left开始
                    _map.erase(pre_it);
                }
                else {
                    // 前一个区间，在left之前
                    pre_it->second = left;
                }
                if (right != old_right) {
                    _map[right] = old_right;
                }
                return;
            }
            else if (pre_it->second > left) {
                // 前一个区间包含了left，不包含right
                if (pre_it->first == left) {
                    _map.erase(pre_it);
                }
                else {
                    _map[pre_it->first] = left;
                };
                // 后续要把left~right之间的区间全删掉
            }
            else {
                // 前一个区间不包含left，不处理，但要把left~right之间的区间全删掉
            }
        }
        while (it != _map.end() && it->first <= right) {
            // 把left~right中的区间删除
            if (it->second <= right) {
                it = _map.erase(it);
            }
            else {
                _map[right] = it->second;
                _map.erase(it);
                break;
            }
        }
    }
};

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

    return 0;
}





