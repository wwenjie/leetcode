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
#include <limits.h> // 包含 INT_MAX
#include <chrono>
#include <numeric> // 包含 std::accumulate
using namespace std;

class Solution {
public:
    /*
    dfs + 记忆化搜素哦
    巧妙的地方在于dfs中，把本次循环中的结果，有一个成功就当作成功，循环调dfs()，只要有一个返回false的也当作成功
    */
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if ((1 + maxChoosableInteger) * maxChoosableInteger / 2 < desiredTotal)
            // 等差数列求和,总和<total
            return false;
        unordered_map<int, bool> memo;
        std::function<bool(int, int)> dfs = [&](int state, int total) {
            if (memo.count(state))
                return memo[state];

            bool ans = false;
            for (int i=1; i<= maxChoosableInteger; ++i) {
                if ((state & (1 << i)) > 0) 
                    continue;
                if (total - i <= 0) {
                    ans = true;
                    break;
                }
                int new_state = state | (1 << i);
                if (!dfs(new_state, total - i)) {
                    ans = true;
                    break;
                }
            }
            memo[state] = ans;
            return ans;
        };
        return dfs(0, desiredTotal);
    }
};

int main()
{
    Solution solution;
    auto start = std::chrono::high_resolution_clock::now();
    int ans = solution.canIWin(10, 11);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::micro> elapsed_time = end - start;
    cout << "ans:" << ans << ", time:" << (elapsed_time.count() / 1000) << "ms" << endl;

    return 0;
}
