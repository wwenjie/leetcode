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
    bitset<100000> bits;
    int maxNumOfMarkedIndices(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        helper(nums, 0, nums.size()-1);
        return bits.count();
    }
    void helper(vector<int>& nums, int start, int end) {
        if (start >= end)
            return;
        int mid = start + (end - start) / 2;
        cout << "mid:" << mid << endl;
        for (int i = start; i<= mid; ++i) {
            if (bits[i] == 1)
                continue;
            for (int j=mid+1; j<=end; ++j) {
                if (bits[j] == 1)
                    continue;
                if (2 * nums[i] <= nums[j]) {
                    bits[i] = 1;
                    bits[j] = 1;
                    cout << "yes--->> "<< nums[i] << ", " << nums[j] << endl;
                    break;
                }
                else {
                    cout << "no --->> " << nums[i] << ", " << nums[j] << endl;
                }
            }
        }
        helper(nums, start, mid);
        helper(nums, mid+1, end);
    }
};


int main()
{
    Solution solution;

    auto start = std::chrono::high_resolution_clock::now();

    vector<int> nums = {9,2,5,4};
    int ans = solution.maxNumOfMarkedIndices(nums);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::micro> elapsed_time = end - start;

    cout << "ans:" << ans << ", time:" << (elapsed_time.count() / 1000) << "ms" << endl;
    int a = 0;
    int b = -a;
    cout << a << "," << b<< endl;
    cout << (a == b) << endl;
    return 0;
}
