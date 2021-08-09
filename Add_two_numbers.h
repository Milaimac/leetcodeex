#include"head.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ret;
        ListNode* tmp = ret;
        bool inc = false;
        while(1){
            int res;
            if(l1 == nullptr&&l2 == nullptr){
                break;
            }
            else if(l1 == nullptr && l2 != nullptr){
                res = l2->val;
            }
            else if(l1 != nullptr && l2 == nullptr){
                res = l1->val;
            }
            else{
                res = l1->val+l2->val;
            }

            if(res >= 10){
                ret->val += res-10;
                if(inc == true){
                    ret->next->val = 1; 
                }
                inc = true;
            }else {
                ret->val = res;
                inc = false;
            }
            l1 = l1->next;l2 = l2->next;ret = ret->next;
        }
        return tmp;
    }
};
