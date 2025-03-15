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
        ListNode* dummy_head = new ListNode(0, head);
        ListNode* cur = head;
        ListNode* last_group_head = dummy_head;
        ListNode* group_head = nullptr;
        int idx = 0;
        while(cur) {
            ListNode* next = cur->next;
            if (idx % k == 0) {
                group_head = cur;
            }
            else if (idx % k == k-1) {
                ListNode* new_head = nullptr;
                std::tie(new_head, std::ignore) = myReverse(group_head, cur);
                last_group_head->next = new_head;
                last_group_head = group_head; // 给下一组用
            }
            cur = next;
            idx++;
        }
        if (idx % k != 0) {
            last_group_head->next = group_head;
        }
        return dummy_head->next;
    }

    pair<ListNode*, ListNode*> myReverse(ListNode* head, ListNode* tail) {
        ListNode* cur = head;
        ListNode* pre = nullptr;
        ListNode* end = tail->next;
        while(cur && cur != end) {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return make_pair(pre, head);
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
    //ListNode* res = solution.myReverse(node2, node3);
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
