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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode* odd_head = new ListNode(0);
        ListNode* odd_tail = odd_head;
        ListNode* even_head = new ListNode(0);
        ListNode* even_tail = even_head;
        ListNode* cur = head;
        int idx = 1;
        while(cur) {
            if (idx & 1) {
                cout << "1--->" << odd_tail->val << "->" << cur->val << endl;

                odd_tail->next = cur;
                odd_tail = cur;
            }
            else {
                cout << "2--->" << even_tail->val << "->" << cur->val << endl;

                even_tail->next = cur;
                even_tail = cur;
            }
            cout << "idx:" << idx << "," << cur->val<< endl;

            cur = cur->next;
            idx++;
        }
        even_tail->next = nullptr; // 少了这行代码，查了半天
        odd_tail->next = even_head->next;
        ListNode* ans = odd_head->next;
        delete odd_head;
        delete even_head;
        cout << "2222" << endl;

        return ans;
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

    
    ListNode* res = solution.oddEvenList(head);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::micro> elapsed_time = end - start;

    std::stringstream ss;
    while (res) {
        //cout << "--->> " << res->val << endl;
        ss << res->val << ",";
        res = res->next;
    }

    cout << "ans:" << ss.str() << ", time:" << (elapsed_time.count() / 1000) << "ms" << endl;

    cout << ((uint64_t)(std::ceil(std::log(1e9)/std::log(2)))) << endl;
    cout << ((uint64_t)(std::ceil(std::log(16)/std::log(2)))) << endl;
    cout << ((uint64_t)(std::ceil(std::log(17)/std::log(2)))) << endl;
    return 0;
}
