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
#include "../util/util.h"

using namespace std;

// 法2：树状数组
class NumArray {
private:
    vector<int> tree_;
    vector<int> nums_;
    int lowBit(int x) {
        // 10100->00100
        return x & -x;
    }
    void add(int index, int val) {
        while(index < tree_.size()) {
            tree_[index] += val;
            index += lowBit(index);
        }
    }
    int prefixSum(int index) {
        // 前缀和
        int sum = 0;
        while (index > 0) {
            sum += tree_[index];
            index -= lowBit(index);
        }
        return sum;
    }
public:
    NumArray(vector<int>& nums): tree_(nums.size()+1), nums_(nums) {
        for (int i=0; i<nums.size(); ++i) {
            add(i+1, nums[i]);
        }
    } 
    
    void update(int index, int val) {
        int add_val = val - nums_[index];
        add(index+1, add_val);
        nums_[index] = val;
    }
    
    int sumRange(int left, int right) {
        return prefixSum(right+1) - prefixSum(left);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */

int main()
{
    // Solution solution;
    // // vector<int> nums = {4,2,1,4,3,4,5,8,15};
    // vector<int> nums = {7,4,5,1,8,12,4,7};

    // auto start = std::chrono::high_resolution_clock::now();
    // int ans = solution.lengthOfLIS(nums, 5);
    // auto end = std::chrono::high_resolution_clock::now();

    // std::chrono::duration<double, std::micro> elapsed_time = end - start;
    // cout << "ans:" << ans << ", time:" << (elapsed_time.count() / 1000) << "ms" << endl;

    vector<int> nums = {1,3,5};
    NumArray* obj = new NumArray(nums);
    int sum = obj->sumRange(0, 2);
    cout << "sum: " << sum << endl;
    obj->update(1, 2);
    sum = obj->sumRange(0, 2);
    cout << "sum: " << sum << endl;

    return 0;
}





