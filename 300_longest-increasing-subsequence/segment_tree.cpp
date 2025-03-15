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
#include <numeric>  // 包含 std::accumulate
#include <cmath>    // 包含 std::floor
#include "../util/util.h"

using namespace std;
class SegmentTree {
private:
    int min_num = 0;
    int max_num = 0;
    vector<int> tree;
    int _query(int node, int start, int end, int l, int r) {
        if (r < start || l > end) {
            return INT_MIN;
        }
        if (l <= start && end <= r) {
            return tree[node];
        }
        
        int mid = 0;
        if (start + end > 0)
            mid = (start + end) / 2;
        else 
            mid = std::floor(((float)(start + end)) / 2);
        if (l > r || node == 0) {
            cout << "exit!!!!" << endl; 
            exit(1);
        }
        int l_max = _query(node * 2, start, mid, l, r);
        int r_max = _query(node * 2 + 1, mid + 1, end, l, r);

        cout << "query ----->>> node:" << node 
             << ",max(l, r) = " << max(l_max, r_max)
             << ",start:" << start
             << ",mid:" << mid
             << ",end:" << end
             << ",l:" << l
             << ",r:" << r << endl;
        return max(l_max, r_max);
    }
    void _update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            // 叶子节点
            tree[node] = val;
            cout << "tree[" << node << "] = " << tree[node]
                 << ",start:" << start << ",end:" << end
                 << " , idx:" << idx << ",val:" << val << endl;
            return;
        }
        // int mid = (start + end) / 2;
        int mid = 0;
        if (start + end > 0)
            mid = (start + end) / 2;
        else 
            mid = std::floor(((float)(start + end)) / 2);
        if (start <= idx && idx <= mid) {
            _update(node*2, start, mid, idx, val);
        }
        else {
            _update(node*2+1, mid+1, end, idx, val);
        }
        tree[node] = max(tree[node*2], tree[node*2+1]);
        cout << "tree[" << node << "] = " << tree[node]
             << ",start:" << start << ",end:" << end
             << " , idx:" << idx << ",val:" << val << endl;
    }
public:
    SegmentTree(int _min_num, int _max_num) : min_num(_min_num),
                                              max_num(_max_num), 
                                              tree((_max_num - _min_num + 2) * 4, 0) {}
    int query(int l, int r) {
        return _query(1, min_num-1, max_num, l, r);
    }
    void update(int idx, int val) {
        return _update(1, min_num-1, max_num, idx, val);
    }
};

class Solution {
public:
    // 法1：线段树
    int lengthOfLIS(vector<int>& nums) {
        int min_num = *std::min_element(nums.begin(), nums.end());
        int max_num = *std::max_element(nums.begin(), nums.end());
        SegmentTree seg_tree(min_num, max_num);
        for (int num: nums) {
            int max_len = seg_tree.query(min_num-1, num-1);
            cout<< "query res: (" << min_num << "," << (num-1) << "), max_len:" << max_len << endl;
            seg_tree.update(num, max_len + 1);
        }
        return seg_tree.query(min_num, max_num);
    }

    /* 法2：dp
        状态转移方程：dp[i] = max(dp[i], dp[j]+1), 0 <= j < i 且 nums[j] < nums[i]
    */
    int lengthOfLIS_2(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        vector<int> dp(n, 1);
        dp[0] = 1;
        for (int i=1; i<n; ++i) {
            for (int j=0; j<i; ++j) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};


int main()
{
    Solution solution;
    //vector<int> nums = {7,7,7,7,7,7,7};
    //vector<int> nums = {0,1,0,3,2,3};
    vector<int> nums = {10,9,2,5,3,7,101,18};

    auto start = std::chrono::high_resolution_clock::now();
    int ans = solution.lengthOfLIS(nums);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::micro> elapsed_time = end - start;
    cout << "ans:" << ans << ", time:" << (elapsed_time.count() / 1000) << "ms" << endl;

    return 0;
}
