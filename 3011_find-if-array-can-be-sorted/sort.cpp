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
#include <algorithm>// 包含 std::sort
#include <limits.h> // 包含 INT_MAX
#include <chrono>
#include <numeric> // 包含 std::accumulate
using namespace std;

class Solution {
public:
    // 选择排序，判断1的位是否相同
    bool canSortArray1(vector<int>& nums) {
        int n = nums.size();
        for (int i=0; i<n-1; ++i) {
            for (int j=i+1; j<n; ++j) {
                if (nums[i] > nums[j]) {
                    if (calSetBitCnt(nums[i]) != calSetBitCnt(nums[j]))
                        return false;
                    swap(nums[i], nums[j]);
                }
            }
        }
        return true;
    }

    // 冒泡排序
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n-1; ++j) {
                if (nums[j] > nums[j+1]) {
                    std::stringstream ss;
                    for (int i : nums) {
                        ss << i << ",";
                    }
                    if (calSetBitCnt(nums[j]) != calSetBitCnt(nums[j+1])) {
                        cout << nums[j] << "," << nums[j+1] << ","
                             << calSetBitCnt(nums[j]) << "," << calSetBitCnt(nums[j+1]) << endl;
                        cout << ss.str() << endl;
                        return false;
                    }
                    swap(nums[j], nums[j+1]);
                }
            }
        }
        return true;
    }


    int calSetBitCnt(int num) {
        int cnt = 0;
        while (num > 0) {
            if (num & 1)
                ++cnt;
            num >>= 1;
        }
        return cnt;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {8,4,2,30,15};

    auto start = std::chrono::high_resolution_clock::now();
    bool ans = solution.canSortArray(nums);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::micro> elapsed_time = end - start;
    cout << "ans:" << ans << ", time:" << (elapsed_time.count() / 1000) << "ms" << endl;

    return 0;
}
