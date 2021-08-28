// 剑指 Offer 22. 链表中倒数第k个节点

#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* low = head, *temp  = head;
        ListNode* fast;
        int i = 0;
        while(i<k){
            fast = temp->next;
            temp = temp->next;
            i++;
        }
        while(fast != nullptr){
            fast = fast->next;
            low = low->next;
        }

        return low;
    }
};

// 1 2 3 4
// 倒数 第2个