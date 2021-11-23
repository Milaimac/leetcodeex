/*
 * @Date: 2021-11-21 20:55:26
 * @LastEditors: kafier
 * @LastEditTime: 2021-11-22 19:44:05
 */
#include "generate_listNode.hpp"
#include <unordered_map>
using namespace std;
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode (0);
        dummy->next = head;
        ListNode* pre = dummy;

        while(head){
            ListNode* tail = pre;
            for(int i = 0;i < k;++i){
                tail = tail->next;
                if(!tail) {
                    return dummy->next;
                }
            }
            ListNode* nex = tail->next;
            tie(head, tail) = reverse(head, tail);
            pre->next = head;
            tail->next = nex;
            pre = tail;
            head = tail->next;
        }
        return dummy->next;
    }

    pair<ListNode*, ListNode*> reverse(ListNode* head, ListNode* tail)
    {
        ListNode* prev = tail->next;
        ListNode* p = head;
        while(prev != tail){
            ListNode* next = p->next;
            p->next = prev;
            prev = p;
            p = next;
        }

        return {tail, head};
    }
};
