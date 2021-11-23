/*
 * @Date: 2021-11-18 22:05:43
 * @LastEditors: kafier
 * @LastEditTime: 2021-11-18 22:24:47
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    /**
     * @description: 
     * @param {ListNode*} l1
     * @param {ListNode*} l2
     * 
     * 将l2 小的插入到l1之间 over。 不 ！ 还是创建一个新的链表
     * @return {*}
     */    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        ListNode* prevHead = new ListNode(-1);
        ListNode* prev = prevHead;
        while(l1 != nullptr || l2 != nullptr)
        {
            if(l1->val >= l2->val){
                prev->next = l2;
                l2 = l2->next;
                // prev = prev->next;
            }
            else
            {
                prev->next = l1;  
                // prev = prev->next;   
                l1 = l1->next;        
            }
            prev = prev->next;
        }

        prev->next = l1 == nullptr ? l2 : l1;

        return prevHead->next;
    }
};