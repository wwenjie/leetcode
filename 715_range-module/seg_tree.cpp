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

// 法2：线段树，超出内存限制，看ylb的题解有对象池CacheObj的代码，去掉对象池也会超出内存限制
// https://leetcode.cn/problems/range-module/solutions/2522984/python3javacgo-yi-ti-yi-jie-xian-duan-sh-uehk/

struct Node {
    Node* left = nullptr;
    Node* right = nullptr;
    bool cover = false;
    int add = 0; // 懒标记，1表示覆盖，-1表示取消覆盖
};

class SegmentTree {
private:
    int n;
    Node root;
    void _update(Node* node, int start, int end, int l, int r, int val) {
        if (l <= start && end <= r) {
            // 如果本节点的start~end范围，在l~r范围内，则更新本节点的cover=true，add=val
            node->cover = (val == 1);
            node->add = val;
            return;
        }
        _pushDown(node);
        int mid = (start + end) / 2;
        if (l <= mid)
            _update(node->left, start, mid, l, r, val);
        if (r > mid)
            _update(node->right, mid+1, end, l, r, val);
        _pushUp(node);
    }
    bool _query(Node* node, int start, int end, int l, int r) {
        if (l <= start && end <= r) {
            // 本node节点在l~r范围内，返回本节点是否被cover
            return node->cover;
        }
        _pushDown(node);
        int mid = (start + end) / 2;
        // 查询左右子树是否被覆盖
        bool is_cover = true;
        if (l <= mid) 
            is_cover = is_cover && _query(node->left, start, mid, l, r);
        if (r > mid)
            is_cover = is_cover && _query(node->right, mid+1, end, l, r);
        return is_cover;
    }
    void _pushUp(Node* node) {
        // 向上更新
        node->cover = node->left->cover && node->right->cover;
    }
    void _pushDown(Node* node) {
        // 向下更新（更新左右子节点）
        if (node->left == nullptr)
            node->left = new Node();
        if (node->right == nullptr)
            node->right = new Node();
        if (node->add == 0)
            return;
        node->left->cover = (node->add == 1);
        node->right->cover = (node->add == 1);
        // node->left->cover = node->cover;
        // node->right->cover = node->cover;
        node->left->add = node->add;
        node->right->add = node->add;
        node->add = 0;
    }
public:
    SegmentTree(int N) : n(N) { }
    void update(int left, int right, int val) {
        return _update(&root, 1, n, left, right-1, val);
    }
    bool query(int left, int right) {
        return _query(&root, 1, n, left, right-1);
    }
};

class RangeModule {
private:
    SegmentTree* seg_tree = nullptr;
public:
    RangeModule() {
        seg_tree = new SegmentTree(1e9);
    }
    ~RangeModule() {
        if (seg_tree != nullptr) {
            delete seg_tree;
            seg_tree = nullptr;
        }
    }
    
    void addRange(int left, int right) {
        seg_tree->update(left, right, 1);
    }
    
    bool queryRange(int left, int right) {
        return seg_tree->query(left, right);
    }
    
    void removeRange(int left, int right) {
        seg_tree->update(left, right, -1);
    }
};

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

    cout << ((uint32_t)1e9) << endl;

    return 0;
}
