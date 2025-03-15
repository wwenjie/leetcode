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

double myPow(double x, int n)
{
    if (n == 0) return 1;
    if (n == 1) return x;
    long long N = abs((long long)n);
    double ans = 1;
    double tmp = x;
    while (N > 0) {
        if (N & 1 > 0) {
            ans *= tmp;
        }
        cout << "N:" << N << ", N & 1:" << (N & 1) << ",ans:" << ans << endl;
        tmp *= tmp;
        N >>= 1;
    }
    return n > 0 ? ans : 1 / ans;
}

int main()
{
    auto start = std::chrono::high_resolution_clock::now();
    int ans = myPow(2, 10);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::micro> elapsed_time = end - start;
    cout << "ans:" << ans << ", time:" << (elapsed_time.count() / 1000) << "ms" << endl;

    return 0;
}
