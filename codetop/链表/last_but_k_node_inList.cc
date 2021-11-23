/*
 * @Date: 2021-11-20 14:49:20
 * @LastEditors: kafier
 * @LastEditTime: 2021-11-20 16:05:04
 */

// 链表中倒数第k个节点
#include <stdio.h>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* node = head;
        for(int i = 0;i < k-1;++i)
        {   
            node = node->next;
        }

        ListNode* cur = head;
        while(node->next)
        {
            cur = cur->next;
            node = node->next;
        }

        return cur;
    }
};