/*
 * @Date: 2021-11-18 10:03:01
 * @LastEditors: kafier
 * @LastEditTime: 2021-11-20 14:27:22
 */
#include <stdio.h>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};



class Solution {
public:
    /**
     * @description: 
     * 和环形链表1相比， 环形链表II需要返回的是那个节点， 而不是判断是否有没有环
     * 虽然同样是快慢指针的方法， 但是不能沿用之前的快慢指针的做法， fast指针以slow指针两倍速进行， 那么设非公共位置的节点数量为a， 是公共数量的节点数量为c,目前相遇的节点为b, 那么 2(a+b) = a+b+Dc， 其中D为常熟
     * 如果环过小， 极大的可能绕环多圈。 
     * 所以无法通过让快慢指针相遇这个方法判断相交的点。  将上述公式换种方式表达， 假设走了进入环后走了b个距离，快慢指针相遇， fast指针走完了n圈， 设置从b到环入口节点的距离为c。 
     * 那么公式为 a+n(b+c)+b = 2(a+b) ---->>>> a = c + (n-1)(b+c), 那么从相遇点到入环点的距离加上n-1圈的环长（c + (n-1)(b+c))， 恰好等于从链表头部到入环点的距离（a）。 
     * 
     * 
     * 所以思路改变。 找到相遇点后。 设置一个指针从head出发。 开始另外设置一个指针从head开始，走了a步， 同样从相遇点开始的slow也走 c + (n-1)(b+c)步， 二者相遇
     * @param {ListNode} *head
     * @return {*}
     */
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head, *fast = head;
        while(fast != nullptr)
        {
            slow = slow->next;
            if(fast->next == nullptr)
            {
                return nullptr;

            }
            fast = fast->next->next;
            if(fast == slow)
            {
                ListNode *ptr = head;
                while(ptr != slow)
                {
                    ptr = ptr->next;
                    slow = slow->next;
                }
                return ptr;
            }
            return nullptr;
        }

        
    }
};