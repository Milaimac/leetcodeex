#include <iostream>
// 剑指offer52 ，两个链表的第一个公共节点
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* node1 = headA;
        ListNode* node2 = headB;
        while (node1 != node2)
        {
            node1 = (node1 == NULL ? headB : node1->next);
            node2 = (node2 == NULL ? headA : node2->next);
        }
        
        return node1;
    }
    
};
// 双指针