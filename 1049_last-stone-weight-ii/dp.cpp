#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <unordered_set>
#include <functional>
#include <limits.h> // 包含 INT_MAX
#include <chrono>
#include <numeric> // 包含 std::accumulate
using namespace std;

/*  
    0/1背包问题
    问题可以转化成把石头分成两份,2份数量可能不均等,但2分重量差值最小
    相当于0/1背包问题,取出总重量最接近sum/2 && 总重量<sum/2的石头,得到的diff就是答案

    法1-a：前i个石头能否凑出重量j：
            dp[i][j] = dp[i-1][j] || dp[i-1][j-stones[i]]
    法2-a：前i个石头，剩余背包重量j，可以取到的最大重量：
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-stones[i]] + stones[i]);
*/

void print_logs(const vector<vector<bool>>& ve2) {
    std::stringstream ss;
    for (const vector<bool>& ve: ve2) {
        for (bool n : ve) {
            ss << n << ",";
        }
        ss << endl;
    }
    cout << ss.str() << endl;
}

    /* 法1-a dp
    状态转移方程:
        前i个石头能否凑出重量j
        dp[i][j] = dp[i-1][j] || dp[i-1][j-stones[i]]
    */
    int lastStoneWeightII_1a(vector<int>& stones) {
        int n = stones.size();
        int sum = std::accumulate(stones.begin(), stones.end(), 0); 
        vector<vector<bool>> dp(n, vector<bool>(sum/2 + 1, false));

        for (int i=0; i<n; ++i)
            dp[i][0] = true;
        for (int j=0; j<=sum/2; ++j) {
            if (stones[0] == j) {
                dp[0][j] = true;
            }
        }

        for (int i=1; i<n; ++i) {
            for (int j=0; j<=sum/2; ++j) {
            //for (int j = sum/2; j >= 0; --j) { // 这样也可以,因为依赖的是前一行的数据
                dp[i][j] = dp[i-1][j];
                if (j >= stones[i]) {
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-stones[i]];
                }
            }
        }
        for (int j=sum/2; j>=0; --j) {
            if (dp[n-1][j])
                return sum - 2* j;
        }
        return -1;
    }

    /* 法1-b: dp + 滚动数组
    原转移方程: dp[i][j] = dp[i-1][j] || dp[i-1][j-stones[i]]
    改为: dp[j] = dp[j] || [j-stones[i]]
    */
    int lastStoneWeightII_1b(vector<int>& stones) {
        int n = stones.size();
        int sum = std::accumulate(stones.begin(), stones.end(), 0); 
        vector<bool> dp(sum/2 + 1, false);

        dp[0] = true;
        if (stones[0] <= sum/2)
           dp[stones[0]] = true;

        for (int i=1; i<n; ++i) {
            for (int j=sum/2; j>=0; --j) {
                if (j >= stones[i]) {
                    dp[j] = dp[j] || dp[j-stones[i]];
                }
            }
        }
        for (int j=sum/2; j>=0; --j) {
            if (dp[j])
                return sum - 2* j;
        }
        return -1;
    }

    /* 法2-a: dp, 跟法1不一样的做法
    状态转移方程:
        dp[i][j] = max(dp[i-1][j], dp[i-1][j-stones[i]] + stones[i]);
    */
    int lastStoneWeightII_2a(vector<int>& stones) {
        int n = stones.size();
        int sum = std::accumulate(stones.begin(), stones.end(), 0); 
        vector<vector<int>> dp(n, vector<int>(sum/2 + 1, 0));
        for (int i=0; i<n; ++i)
            dp[i][0] = 0;
        for (int j=0; j<= sum/2; ++j)
            if (j >= stones[0])
                dp[0][j] = stones[0];
        for (int i=1; i<n; ++i) {
            for (int j=sum/2; j>=0; --j) {
                dp[i][j] = dp[i-1][j];
                if (j >= stones[i])
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-stones[i]] + stones[i]);
            }
        }
        return sum - 2 * dp[n-1][sum/2];
    }


    /* 法2-b: dp, 在法1-a基础上,加滚动数组优化
    状态转移方程:
        dp[j] = max([j], dp[j-stones[i]] + stones[i]);
    */
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int sum = std::accumulate(stones.begin(), stones.end(), 0); 
        vector<int> dp(sum/2 + 1, 0);
        for (int i=0; i<n; ++i)
            dp[0] = 0;
        for (int j=0; j<= sum/2; ++j)
            if (j >= stones[0])
                dp[j] = stones[0];
        for (int i=1; i<n; ++i) {
            for (int j=sum/2; j>=0; --j) {
                if (j >= stones[i])
                    dp[j] = max(dp[j], dp[j-stones[i]] + stones[i]);
            }
        }
        return sum - 2 * dp[sum/2];
    }

int main()
{
    vector<int> stones = {2, 7, 4, 1, 8, 1};

    auto start = std::chrono::high_resolution_clock::now();
    int ans = lastStoneWeightII(stones);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::micro> elapsed_time = end - start;
    cout << "ans:" << ans << ", time:" << (elapsed_time.count() / 1000) << "ms" << endl;

    return 0;
}
