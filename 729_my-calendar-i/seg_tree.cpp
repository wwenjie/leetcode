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


// 法2：线段树，区域写，区域查，懒标记
class MyCalendar {
private:
    struct Node {
        Node* left = nullptr;
        Node* right = nullptr;
        int book = 0; // left~right范围内被预定了多少天
        int add = 0; // 1:预定，0:未预定，-1:取消预订
    };
    int n_ = 0;
    Node root_;
    void update(Node* node, int node_l, int node_r, int l, int r, int val) {
        if (l <= node_l && node_r <= r) {
            node->book += (node_r - node_l + 1) * val;
            node->add += val;
            return;
        }
        pushDown(node, node_r - node_l + 1);
        int mid = (node_l + node_r) / 2;
        if (l <= mid)
            update(node->left, node_l, mid, l, r, val);
        if (r > mid)
            update(node->right, mid+1, node_r, l, r, val);
        pushUp(node);
    }
    int query(Node* node, int node_l, int node_r, int l, int r) {
        if (l <= node_l && node_r <= r) {
            return node->book;
        }
        pushDown(node, node_r - node_l + 1);
        int mid = (node_l + node_r) / 2;
        bool ans = 0;
        if (l <= mid)
            ans += query(node->left, node_l, mid, l, r);
        if (r > mid)
            ans += query(node->right, mid+1, node_r, l, r);
        return ans;
    }
    void pushDown(Node* node, int len) {
        if (node->left == nullptr)
            node->left = new Node();
        if (node->right == nullptr)
            node->right = new Node();
        if (node->add == 0)
            return;
        node->left->book += (len/2) * node->add;
        node->right->book += (len - len/2) * node->add;
        node->left->add += node->add;
        node->right->add += node->add;
        node->add = 0;
    }
    void pushUp(Node* node) {
        node->book = node->left->book + node->right->book;
    }
public:
    MyCalendar() {
        n_ = 1e9;
    }

    bool book(int start, int end) {
        if (query(&root_, 0, n_, start, end-1) > 0) {
            return false;
        }
        update(&root_, 0, n_, start, end-1, 1);
        return true;
    }

    int query(int start, int end) {
        return query(&root_, 0, n_, start, end-1);
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
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

    MyCalendar* obj = new MyCalendar();
    bool ans = obj->book(10, 20);
    cout << "ans: " << ans << endl;
    int book_days = obj->query(15,25);
    cout << "book_days: " << book_days << endl;
    book_days = obj->query(10,11);
    cout << "book_days: " << book_days << endl;
    // ans = obj->book(15, 25);
    // cout << "ans: " << ans << endl;

    return 0;
}





