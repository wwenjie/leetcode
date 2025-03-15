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
           
struct ListNode {
    int val;    
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || k == 1)
            return head;
        ListNode* dummy_head = new ListNode(0, head);
        ListNode* group_pre = dummy_head; // 本group的pre节点
        ListNode* next_group_pre = nullptr; // 下一个group的pre节点
        ListNode* cur = head;
        ListNode* pre = nullptr;
        int idx = 0;
        while(cur) {
            if (idx % k == 0) {
                // 组内第一个元素
                next_group_pre = cur; // 1,3
                pre = nullptr; 
            }
            else if (idx % k == k-1) {
                // 组内最后一个元素
                group_pre->next = cur; // 2
                // group_pre赋值为新的，给下一个group用
                group_pre = next_group_pre; // 1
            }
            // group内
            ListNode* next = cur->next;
            cur->next = pre; // nullptr,1
            cout << cur->val << "->" << (pre ? pre->val : 0) << endl;
            pre = cur; // 1,2
            cur = next; // 2,3
            idx++;
        }
        if (idx % k != 0) {
            group_pre->next = pre;
        }
        return dummy_head->next;
    }
};

int main()
{
    Solution solution;

    auto start = std::chrono::high_resolution_clock::now();

    ListNode* head = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    head->next = node2;
    ListNode* node3 = new ListNode(3);
    node2->next = node3;
    ListNode* node4 = new ListNode(4);
    node3->next = node4;
    ListNode* node5 = new ListNode(5);
    node4->next = node5;

    
    ListNode* res = solution.reverseKGroup(head, 2);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::micro> elapsed_time = end - start;

    std::stringstream ss;
    while (res) {
        ss << res->val << ",";
        res = res->next;
    }

    cout << "ans:" << ss.str() << ", time:" << (elapsed_time.count() / 1000) << "ms" << endl;


    return 0;
}
