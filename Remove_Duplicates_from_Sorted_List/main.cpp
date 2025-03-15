ListNode* deleteDuplicates(ListNode* head) {
    if (!head)
        return head;
    auto cur = head;
    while(cur->next){
        if (cur->val == cur->next->val)
            cur->next = cur->next->next;
        else
            cur = cur->next;
    }
    return head;
}
