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
    法2：滑动窗口，O(s_len + t_len)
    */
    string minWindow(string s, string t) {
        int less = 0;
        map<char, int> target;
        for (char& ch: t) {
            target[ch]++;
            less++;
        }
        map<char, int> char_cnt;
        int n = s.size();
        int min_len = INT_MAX;
        int res_l = 0;
        int res_r = 0;
        int l = 0, r = 0;
        
        char_cnt[s[r]]++;
        if (target.count(s[r]))
            less--;
        while (l <= r && r < n) {
            cout << "l:" << l << ",r:" << r << ", " << n  << ", =====>> less:" << less << endl;

            if (less == 0) {
                if (r - l + 1 < min_len) {
                    min_len = r - l + 1;
                    res_l = l;
                    res_r = r;
                }
                cout << "l:" << l << ",r:" << r << ", "
                     << "char_cnt:" << char_cnt[s[l]] << ",target_cnt:" << target[s[l]] << ",";
                print_map(char_cnt);
                // l下标右移
                char_cnt[s[l]]--;
                if (char_cnt[s[l]] < target[s[l]]) {
                    less++;
                }
                l++;
                cout << "less: " << less << endl;
            }
            else {
                // r下标右移
                r++;
                if (char_cnt[s[r]] < target[s[r]])
                    less--;
                char_cnt[s[r]]++;
            }
        }
        cout << "res_l:" << res_l << ",min_len:" << min_len << endl;;
        return min_len < INT_MAX ? s.substr(res_l, min_len) : "";
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
