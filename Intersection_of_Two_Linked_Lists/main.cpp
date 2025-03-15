#include <iostream>

using namespace std;

    // 思路：得到2个链表长度，分别m、n，且m>n，则长链表从m-n处开始遍历，短链表从头开始遍历

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (!headA || !headB)
        return nullptr;
    int lenA = 1;
    int lenB = 1;
    ListNode *nodeA = headA;
    ListNode *nodeB = headB;
    while(nodeA->next){
        lenA++;
        nodeA = nodeA->next;
    }
    while(nodeB->next){
        lenB++;
        nodeB = nodeB->next;
    }
    nodeA = headA;
    nodeB = headB;
    if (lenA > lenB) {
        int diff = lenA - lenB;
        while(diff--) {
            nodeA = nodeA->next;
        }
    }
    else{
        int diff = lenB - lenA;
        while(diff--){
            nodeB = nodeB->next;
        }
    }
    while(nodeA){
        if (nodeA == nodeB){
            return nodeA;
        }
        nodeA = nodeA->next;
        nodeB = nodeB->next;
    }
    return nullptr;
}
