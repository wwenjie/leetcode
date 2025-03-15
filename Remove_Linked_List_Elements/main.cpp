/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

/* 递归
ListNode* removeElements(ListNode* head, int val) {
    if (head == nullptr)
        return head;   
    head->next = removeElements(head->next, val);
    return head->val == val ? head->next : head;
}
*/

// 迭代
ListNode* removeElements(ListNode* head, int val) {
    ListNode* temp = new ListNode(0);
    temp->next = head;
    ListNode* node = temp;
    while(node->next){
        if(node->next->val == val)
            node->next = node->next->next;
        else
            node = node->next;
    }
    return temp->next;
}
