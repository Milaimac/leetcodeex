/*
 * @Date: 2021-11-18 10:03:01
 * @LastEditors: kafier
 * @LastEditTime: 2021-11-18 21:54:15
 */
/*
 * @Date: 2021-11-18 10:03:01
 * @LastEditors: kafier
 * @LastEditTime: 2021-11-18 21:54:11
 */
#include <stdio.h>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head->next == NULL || head->next->next == NULL){
            return false;
        }
        ListNode* low = head;
        ListNode* fast = head->next;
        while(low != fast){
            // low = low->next;
            if(fast == NULL || fast->next == NULL){
                return false;
            }
            low = low->next;
            fast = fast->next->next;
        }
        return true;
    }
};