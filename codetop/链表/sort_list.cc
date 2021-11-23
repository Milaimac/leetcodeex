/*
 * @Date: 2021-11-20 17:55:45
 * @LastEditors: kafier
 * @LastEditTime: 2021-11-20 17:55:59
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
     * 归并排序， 要注意分治和归并
     * 大小的比较， 通常是再归并的时候进行比较
     * 顶层归并排序
     * 需要注意顶层排序的初始条件（也可以说是递归最深处的跳出条件） 通常是分治是分到只有一个节点。 至于找中间节点可以通过使用快慢指针来实现。 
     * @param {ListNode*} head
     * @return {*}
     */
    ListNode* sortList(ListNode* head) {
         
    }
    ListNode* sortList(ListNode* head, ListNode* tail){
        if(head == nullptr){
            return head;
        }
        if(head->next == tail){
            head->next = nullptr;
            return head;    
        }
        ListNode* slow = head, *fast = head;
        while(fast != tail){
            slow = slow->next;
            fast = fast->next;
            if(fast != tail)
            {
                fast = fast->next;
            }
            ListNode* mid = slow;
            return merge(sortList(head, mid), sortList(mid, tail));
        }
    }
};