/*
 * @Date: 2021-11-20 16:07:00
 * @LastEditors: kafier
 * @LastEditTime: 2021-11-20 16:29:17
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
     * // 找到这个被删除节点的前一个节点， 然后揭掉即可
     * @param {ListNode*} head
     * @param {int} n
     * @return {*}
     */
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        for(int i = 1;i < n;++i)
        {
            fast = fast->next;
            if(fast == nullptr){
                // n比链表长度还大
                return nullptr;
            }
        }

        ListNode* prev = head;
        if(fast->next == nullptr)
        {
            return head->next;
        }
        while(fast->next->next != nullptr )
        {
            prev = prev->next;
            fast = fast->next;
        }
        ListNode* next = prev->next->next;
        prev->next = next;
        return head;
    }
};
