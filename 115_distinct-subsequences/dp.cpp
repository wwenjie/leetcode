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
    法1：动态规划
    dp[i][j] 表示 t前i个字符，在出现s的前j个字符中 出现多少次
    初始
        dp[0][0] = 1
    dp[i][j] = dp[i-1][j-1], if t[i-1] == s[j-1]
    dp[i][j] = dp[i][j-1], 剔除s[j-1]
    */
    int numDistinct1(string s, string t) {
        const int MOD = 1e9 + 7;
        int m = s.size();
        int n = t.size();
        vector<vector<uint64_t>> dp(n+1, vector<uint64_t>(m+1));
        for (int j=0; j<=m; ++j)
            dp[0][j] = 1;
        for (int i=1; i<=n; ++i) {
            for (int j=1; j<=m; ++j) {
                if (t[i-1] == s[j-1]) {
                    dp[i][j] = dp[i-1][j-1] % MOD;
                }
                dp[i][j] = (dp[i][j] + dp[i][j-1]) % MOD;
            }
        }
        return dp[n][m];
    }

    // 法2：同上，但两层遍历是先遍历s，后遍历t
    int numDistinct(string s, string t) {
        const int MOD = 1e9 + 7;
        int m = s.size();
        int n = t.size();
        vector<vector<uint64_t>> dp(m+1, vector<uint64_t>(n+1));
        for (int i=0; i<=m; ++i)
            dp[i][0] = 1;
        for (int i=1; i<=m; ++i) {
            for (int j=1; j<=n; ++j) {
                if (s[i-1] == t[j-1]) {
                    dp[i][j] = dp[i-1][j-1] % MOD;
                }
                dp[i][j] = (dp[i][j] + dp[i-1][j]) % MOD;
            }
        }
        return dp[m][n];
    }
};

int main()
{
    Solution solution;

    auto start = std::chrono::high_resolution_clock::now();

    int ans = solution.numDistinct("babgbag", "bag");
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::micro> elapsed_time = end - start;

    cout << "ans:" << ans << ", time:" << (elapsed_time.count() / 1000) << "ms" << endl;
    return 0;
}
