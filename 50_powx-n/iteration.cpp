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

// 法1 快速幂,递归
double myPow(double x, int n) {
    long long N = n; // 防止n==INT_MIN,后面取负数的时候会溢出
    return N > 0 ? quickMul(x, N) : 1 / quickMul(x, -N);
}

double quickMul(double x, long long N) {
    if (N == 0)
        return 1.0;
    double y = quickMul(x, N / 2);
    return N % 2 == 0 ? y * y : y * y * x;
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
