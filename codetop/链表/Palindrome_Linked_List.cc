/*
 * @Date: 2021-11-21 15:59:40
 * @LastEditors: kafier
 * @LastEditTime: 2021-11-21 16:50:10
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
     * 思路：
     * 找到中点（靠近左侧的中点）， 
     * @param {ListNode*} head
     * @return {*}
     */
    bool isPalindrome(ListNode* head) {
        if(head == nullptr){
            return true;
        }
        ListNode* firstHalfEnd = endOfFirstHalf(head);
        ListNode* secondHalfStart= reverseList(firstHalfEnd->next);

        ListNode* p1 = head;
        ListNode* p2 = secondHalfStart;
        bool result = true;

        while(result && p2 != nullptr) // 如果链表节点为奇数， 那么需要右边链表部分来作为一个标记
        {
            if(p1->val != p2->val){
                return false;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        // 还原链表并返回结构
        firstHalfEnd->next = reverseList(secondHalfStart);
        return result;
    }
    ListNode* reverseList(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* curr = head;
        
        while(curr != nullptr)
        {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev->next;
    }
    ListNode* endOfFirstHalf(ListNode* head){
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast->next != nullptr && fast->next->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};