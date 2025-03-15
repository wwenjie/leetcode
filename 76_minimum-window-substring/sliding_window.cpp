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
    法1：滑动窗口，O(128 * s_len + t_len)
    */
    string minWindow(string s, string t) {
        map<char, int> target;
        for (char& ch: t) {
            target[ch]++;
        }
        map<char, int> char_cnt;
        int n = s.size();
        int min_len = INT_MAX;
        int res_l = 0;
        int res_r = 0;
        int l = 0, r = 0;
        char_cnt[s[r]]++;
        while (l <= r && r < n) {
            if (checkCharCnt(target, char_cnt)) {
                if (r - l + 1 < min_len) {
                    min_len = r - l + 1;
                    res_l = l;
                    res_r = r;
                }
                cout << "l:" << l << ",r:" << r << ", "
                     << "char_cnt:" << char_cnt[s[l]] << ",target_cnt:" << target[s[l]] << ",";
                print_map(char_cnt);
                char_cnt[s[l]]--;
                l++;
            }
            else {
                r++;
                char_cnt[s[r]]++;
            }
        }
        return min_len < INT_MAX ? s.substr(res_l, min_len) : "";
    }

    bool checkCharCnt(map<char,int>& target, map<char,int>& char_cnt) {
        for (auto& ch2cnt: target) {
            char ch = ch2cnt.first;
            if (char_cnt[ch] < ch2cnt.second)
                return false;
        }
        return true;
    }
};

int main()
{
    Solution solution;

    auto start = std::chrono::high_resolution_clock::now();

    string s = "ADOBECODEBANC";
    string t = "ABC";

    string ans = solution.minWindow(s, t);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::micro> elapsed_time = end - start;

    cout << "ans:" << ans << ", time:" << (elapsed_time.count() / 1000) << "ms" << endl;
    return 0;
}
