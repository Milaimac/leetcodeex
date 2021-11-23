/*
 * @Date: 2021-11-19 00:19:05
 * @LastEditors: kafier
 * @LastEditTime: 2021-11-19 09:22:09
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
     * @param {ListNode*} head
     * 设置一个空指针， 
     * @return {*}
     */
    ListNode* reverseList(ListNode* head) {
        // d-    
        ListNode* prev = nullptr;
        ListNode* cur = head;
        while(cur){
             
            ListNode* next = cur->next;
            // 它的下一个节点是上一个节点。 cur->next 已经被保存了下来， 方便遍历到后面的节点。 
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
};