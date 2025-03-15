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

class SegmentTree {
private:
    const int n; // 节点数
    vector<int> tree; // 线段树，本题只要单点更新，不需要lazy，val是该线段的最大值
    void _update(int node, int start, int end, int idx, int val) {
        // node是tree中的下标，idx是原始数组中的下标
        if (start == end)
            // 叶子节点
            tree[node] = val;
        else {
            // 非叶子节点
            int mid = (start + end) / 2;
            if (start <= idx && idx <= mid)
                // 左子节点
                _update(2*node, start, mid, idx, val);
            else
                // 右子节点
                _update(2*node+1, mid+1, end, idx, val);
            tree[node] = max(tree[2 * node], tree[2 * node + 1]);
        }
    }
    int _query(int node, int start, int end, int l, int r) {
        // 查询下标l~r之间的最值
        if (r < start || end < l)
            return INT_MIN;
        if (l <= start && end <= r)
            // 本节点的start~end范围在l~r之间，返回本节点的最值
            return tree[node];
        int mid = (start + end) / 2;
        int l_max = _query(2*node, start, mid, l, r);
        int r_max = _query(2*node+1, mid+1, end, l, r);
        return max(l_max, r_max);
    }
public:
    SegmentTree(int size) : tree(4  * size) , n(size) {}
    void update(int idx, int val) {
        // 将原始数组idx下标的值更新为val，因为刚构造的线段树是所有val=0
        return _update(1, 0, n-1, idx, val);
    }
    int query(int l, int r) {
        // 查询原始数组中下标为l~r间的最值
        return _query(1, 0, n-1, l, r);
    }
};

class Solution {
public:
    /*
    法4 线段树，O(nlogm)，m是nums中最大值
    */
    int lengthOfLIS(vector<int>& nums, int k) {
        int max_num = *max_element(nums.begin(), nums.end());
        SegmentTree seg_tree(max_num + 1);
        int ans = 1;
        for (int num: nums) {
            // 获取 num-k ~ num-1 的最大值
            int tmp_max = seg_tree.query(num-k, num-1);
            seg_tree.update(num, tmp_max + 1);
        }
        return seg_tree.query(0, max_num);
    }
};

int main()
{
    Solution solution;
    // vector<int> nums = {4,2,1,4,3,4,5,8,15};
    vector<int> nums = {7,4,5,1,8,12,4,7};

    auto start = std::chrono::high_resolution_clock::now();
    int ans = solution.lengthOfLIS(nums, 5);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::micro> elapsed_time = end - start;
    cout << "ans:" << ans << ", time:" << (elapsed_time.count() / 1000) << "ms" << endl;

    return 0;
}
