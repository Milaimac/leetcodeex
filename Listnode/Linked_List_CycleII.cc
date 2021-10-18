#include <iostream>
using namespace std;

// 142. 环形链表 II
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // 使用双指针来判断
        // 如何推理出 快指针走两步， 慢指针走一步，相交的那个点便是目标掉
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != nullptr)
        {
            slow = slow->next;
            if(fast->next == nullptr)
            {   // 没有环
                return nullptr;
            }
            fast = fast->next->next;
            if(fast == slow)
            {
                ListNode* ptr = head;
                while(ptr != slow)
                {
                    ptr = ptr->next;
                    slow = slow->next;
                }
                return ptr;
            }
        }
        return nullptr;
    }
};