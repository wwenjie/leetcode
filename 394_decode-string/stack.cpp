#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string>
#include <vector>
#include <queue>
#include <stack>
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
    string decodeString(string s) {
        stack<string> stk;
        int n = s.size();
        string res;
        for (int i=0; i<n; ++i) {
            if ('0' <= s[i] && s[i] <= '9') {
                if (i-1 >= 0 && '0' <= s[i-1] && s[i-1] <= '9') {
                    stk.top() += s[i];
                }
                else
                    stk.push(s.substr(i,1));
            }
            else if (s[i] == '[') {
                stk.push("");
            }
            else if (s[i] == ']') {
                string str = stk.top();
                stk.pop();
                int k = stoi(stk.top());
                stk.pop();
                string kstr = "";
                for (int i=0; i<k; ++i) {
                    kstr += str;
                }
                if (stk.empty())
                    res += kstr;
                else {
                    stk.top() += kstr;
                }
            }
            else {
                if (stk.empty())
                    res += std::string(1, s[i]);
                else {
                    stk.top() += std::string(1, s[i]);
                }
            }
        }
        return res;
    }
};


int main()
{
    Solution solution;

    auto start = std::chrono::high_resolution_clock::now();

    // string s = "3[a]2[bc]";
    //string s = "2[abc]3[cd]ef";
    string s = "12[abc]";
    string ans = solution.decodeString(s);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::micro> elapsed_time = end - start;

    cout << "ans:" << ans << ", time:" << (elapsed_time.count() / 1000) << "ms" << endl;

    int a = 1e9 * 2 + 2;
    int b = 1e9 * 2 + 3;
    int mod = 1e9 * 2;
    int c = (a + b) % mod;
    int d = (a % mod) + (b % mod);
    cout << a << "," << b << "," << c << "," << d << endl;

    return 0;
}
