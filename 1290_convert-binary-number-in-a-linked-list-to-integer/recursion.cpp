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
    // 递归
    int getDecimalValue(ListNode* head) {
        int sum = 0, idx = 0;
        std::tie(sum, idx) = helper(head);
        return sum;
    }
    pair<int,int> helper(ListNode* node) {
        int sum = 0;
        int idx = 0;
        if (node->next == nullptr) {
            sum += node->val;
            return make_pair(sum,1);
        }
        std::tie(sum, idx) =  helper(node->next);
        if (node->val)
            sum += (1 << idx);
        cout << "idx:" << idx << ",val:" << node->val << ", sum:" << sum << endl;
        return make_pair(sum, idx+1);
    }
};

int main()
{
    Solution solution;

    auto start = std::chrono::high_resolution_clock::now();

    ListNode* node3 = new ListNode(1);
    ListNode* node2 = new ListNode(0, node3);
    ListNode* head = new ListNode(1, node2);


    int ans = solution.getDecimalValue(head);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::micro> elapsed_time = end - start;

    cout << "ans:" << ans << ", time:" << (elapsed_time.count() / 1000) << "ms" << endl;
    return 0;
}
