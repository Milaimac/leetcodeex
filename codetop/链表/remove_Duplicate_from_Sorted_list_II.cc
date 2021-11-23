/*
 * @Date: 2021-11-20 16:30:57
 * @LastEditors: kafier
 * @LastEditTime: 2021-11-20 17:05:36
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// class Solution {
// public:
//     ListNode* deleteDuplicates(ListNode* head) {
//         ListNode* fast = head;
//         ListNode* low = head;
//         if(fast == nullptr && fast->next == nullptr)
//         {
//             return  head;
//         }
//         fast = fast->next;
//         while(fast->next != nullptr)
//         {
//             // if(low->val != fast->val){
//             //     fast = fast->next;
//             //     low = low->next;
//             // }
//             while(fast->val == low->val && fast != nullptr){
//                 fast = fast->next;
//                 low->next = fast;
//             }

//             fast = fast->next;
//             low = low->next;

//         }
//         return head;    
//     }
// };
class Solution {
public:
    // 要求去除所有重复的节点， 而不是保存一个节点， 那么这种情况确实需要一个dummyHead 
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head){
            return  nullptr;
        }
        ListNode* dummy = new ListNode(0, head);
        ListNode* cur = dummy;
        while(cur->next && cur->next->next)
        {
            if(cur->next->val == cur->next->next->val)
            {
                int x = cur->next->val;
                while(cur->next && cur->next->val == x){ // 如果改成了cur->next->next->val == x， 那么就可以保留一个节点（重复的） 
                    cur->next = cur->next->next;
                }
            }
            else{
                // 通过这个写法， 就可以把重复的节点全部去除。 
                
                cur = cur->next;
            }
        }
        return dummy->next;
    }
};
