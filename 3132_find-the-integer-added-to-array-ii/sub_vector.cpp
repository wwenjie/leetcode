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
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        // vector<int> max1 = getMaxSortedInterger(nums1, 5);
        // vector<int> max2 = getMaxSortedInterger(nums2, 3);
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());
        print_vector(nums1);
        print_vector(nums2);
        for (int i=2; i>=0; --i) {
            // nums2[0] - nums1的前3个数，至少其中1个就是结果
            int x = nums2[0] - nums1[i];

            // 判断nums2是否{nums1[j] + x}的子序列
            for (int j=0,k=0; j<nums1.size() && k<nums2.size(); ++j) {
                if (nums1[j] + x == nums2[k])
                    k++;
                if (k == nums2.size())
                    return x;
            }
        }
        return 0;
    }
    /* 一定要排序整个数组
    vector<int> getMaxSortedInterger(vector<int>& nums, int cnt) {
        // 取出nums中最大的前cnt位
        int n = (nums.size() < cnt ? nums.size() : cnt); 
        for (int i=0; i<n; ++i) {
            for (int j=i; j<nums.size(); ++j) {
                if (nums[i] < nums[j]) {
                    swap(nums[i], nums[j]);
                }
            }
        }
        return vector<int>(nums.begin(), nums.begin()+n);
    }
    */
};


int main()
{
    Solution solution;

    auto start = std::chrono::high_resolution_clock::now();

    vector<int> nums1 = {4,20,16,12,8};
    vector<int> nums2 = {14,18,10};

    int ans = solution.minimumAddedInteger(nums1, nums2);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::micro> elapsed_time = end - start;

    cout << "ans:" << ans << ", time:" << (elapsed_time.count() / 1000) << "ms" << endl;
    return 0;
}
