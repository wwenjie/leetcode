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


// 法2：线段树
class NumArray {
private:
    int n;
    vector<int> tree;
    void _update(int node, int start, int end, int index, int val) {
        cout << "00------>>>" << node <<","
             << start << "," << end << "," << index << "," << val << endl;
        if (start == end) {
            // 叶子节点
            tree[node] = val;
            cout << "11------>>>" << node <<","
                 << start << "," << end << "," << index << "," << val << endl;
            return;
        }
        if (node == -1) exit(1);
        int mid = (start + end) / 2;
        if (index <= mid)
            _update(node*2, start, mid, index, val);
        else
            _update(node*2+1, mid+1, end, index, val);
        tree[node] = tree[node*2] + tree[node*2+1];
        cout << "22------>>>" << node <<","
                 << start << "," << mid << "," << end << ","
                 << index << "," << val << endl;
    }
    int _query(int node, int start, int end, int l, int r) {
        if (l <= start && end <= r) {
            return tree[node];
        }
        int mid = (start + end) / 2;
        int sum = 0;
        if (l <= mid)
            sum += _query(node*2, start, mid, l, r);
        if (r > mid)
            sum += _query(node*2+1, mid+1, end, l, r);
        return sum;
    }
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        tree.resize(n*4, 0);
        for (int i=0; i<n; ++i)
            _update(1, 0, n-1, i, nums[i]);
    }
    
    void update(int index, int val) {
        cout << "update--->>" << index << "," << val << endl;
        _update(1, 0, n-1, index, val);
    }
    
    int sumRange(int left, int right) {
        return _query(1, 0, n-1, left, right);
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





