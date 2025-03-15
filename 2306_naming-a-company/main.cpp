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
    acnt baaa bcnt
    */
    long long distinctNames(vector<string>& ideas) {
        unordered_set<string> groups[26];
        for (auto& s : ideas) {
            groups[s[0] - 'a'].insert(s.substr(1)); // 按照首字母分组
        }
        long long ans = 0;
        for (int a=0; a<25; ++a) {
            for (int b=a+1; b<26; ++b) {
                int m = 0; // 交集的大小
                for (const string& s: groups[a]) {
                    if (groups[b].empty())
                        continue;
                    m += groups[b].count(s);
                    cout << "m:" << m<<",a:" << a << ",b:" << b << ",s:" << s << endl;

                }
                if (groups[a].size() > 0 && groups[b].size() > 0) {
                    cout << "a_size:" << groups[a].size() << ",b_size:" << groups[b].size() << ",m:" << m << endl;
                }
                ans += (long long) (groups[a].size() - m) * (groups[b].size() - m);
            }
        }
        return ans * 2;
    } 
};

int main()
{
    Solution solution;

    auto start = std::chrono::high_resolution_clock::now();

    vector<string> ideas = {"acnt", "daaa", "dcnt"};
    // vector<string> ideas = {"coffee","donuts","time","toffee"};
    
    uint64_t ans = solution.distinctNames(ideas);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::micro> elapsed_time = end - start;

    cout << "ans:" << ans << ", time:" << (elapsed_time.count() / 1000) << "ms" << endl;

    return 0;
}
