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


// 法1：线段树+懒标记，范围更新，范围查询，区间最值问题
class MyCalendarTwo {
private:
    struct Node {
        Node* left = nullptr;
        Node* right = nullptr;
        int val = 0; // left~right区间内的最大值
        int add = 0;
    };
    Node root;

    void update(Node* node, int start, int end, int l, int r, int val) {
        if (l <= start && end <= r) {
            node->add += val;
            node->val += val;
            return;
        }
        lazzyBuild(node);
        pushDown(node);
        int mid = (start + end) / 2;
        if (l <= mid)
            update(node->left, start, mid, l, r, val);
        if (r > mid)
            update(node->right, mid+1, end, l, r, val);
        pushUp(node);
    }
    int query(Node* node, int start, int end, int l, int r) {
        if (l <= start && end <= r) {
            return node->val;
        }
        lazzyBuild(node);
        pushDown(node);
        int mid = (start + end) / 2;
        int max_val = 0;
        if (l <= mid)
            max_val = max(max_val, query(node->left, start, mid, l, r));
        if (r > mid)
            max_val = max(max_val, query(node->right, mid+1, end, l, r));
        return max_val;
    }

    void lazzyBuild(Node* node) {
        if (node->left == nullptr)
            node->left = new Node();
        if (node->right == nullptr)
            node->right = new Node();
    }
    void pushDown(Node* node) {
        if (node->add == 0)
            return;
        node->left->add += node->add;
        node->right->add += node->add;
        node->left->val += node->add;
        node->right->val += node->add;
        node->add = 0;
    }
    void pushUp(Node* node) {
        node->val = max(node->left->val, node->right->val);
    }
    
public:
    MyCalendarTwo() {
    }
    
    bool book(int start, int end) {
        if (query(&root, 0, 1e9, start, end-1) >= 2) {
            return false;
        }
        update(&root, 0, 1e9, start, end-1, 1);
        return true;
    }

    int query(int start, int end) {
        return query(&root, 0, 1e9, start, end-1);
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
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

    MyCalendarTwo* obj = new MyCalendarTwo();
    bool ans = obj->book(10, 20);
    cout << "ans: " << ans << endl;
    ans = obj->book(10, 40);
    cout << "ans: " << ans << endl;

    int val = obj->query(5,15);
    cout << "val: " << val << endl;
    val = obj->query(10,11);
    cout << "val: " << val << endl;
    // ans = obj->book(15, 25);
    // cout << "ans: " << ans << endl;

    return 0;
}





