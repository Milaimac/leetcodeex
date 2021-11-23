/*
 * @Date: 2021-11-18 23:56:20
 * @LastEditors: kafier
 * @LastEditTime: 2021-11-21 08:16:21
 */

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    /**
     * @description: 
     * 反转left到right部分后， 需要能够再拼接起来。 所以还要记录left的上一个节点， right 的下一个节点。第一次写理解错题意， 这个left指的是序号， 而不是对应的值
     * 通过将对应需要反转的链表给隔离出来而后进行反转。 时间复杂度为O(n)
     * @param {ListNode*} head
     * @param {int} left
     * @param {int} right
     * @return {*}
     */
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        // 因为头节点可能会发生变化， 使用虚拟头节点可以避免复杂的分了讨论。
        ListNode *dummyNode = new ListNode(-1);
        dummyNode->next = head;
        // 从虚拟头节点走left - 1步， 来到left节点的前一个节点
        ListNode *pre = dummyNode;
        for (int i = 0; i < left - 1; ++i)
        {
            pre = pre->next;
        }

        // 第二步 从pre再走 right - left + 1步， 来到right节点
        ListNode *rightNode = pre;
        for (int i = 0; i < right - left + 1; ++i)
        {
            rightNode = rightNode->next;
        }
        // 第三步， 切断一个子链表（截取链表）
        ListNode *leftNode = pre->next;
        ListNode *curr = rightNode->next; // 这是一个要点， 因为反转后， 最后的节点就是最前的节点了， 所以才将这个节点设置为curr

        // 切断连接
        pre->next = nullptr;
        rightNode->next = nullptr;
        // 接回到原来的链表中
        reverseLinkedList(leftNode);
        pre->next = rightNode;
        leftNode->next = curr;
        return dummyNode->next;
    }

    void reverseLinkedList(ListNode *head)
    {
        ListNode *prev = nullptr;
        ListNode *cur = head;

        while (cur != nullptr)
        {
            ListNode *next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
    }
};

class Solution1
{
public:
    /**
     * @description: 
     * 使用一次遍历的情况完成反转。 
     * 将curr 的下一个节点记录为next， 
     * 将curr 的下一个节点指向next的下一个节点
     * 将next的下一个节点指向pre的下一个节点 （这个操作相当与把next这个节点挤到pre的后面， 
     * 将pre的下一个节点指向next
     * @param {ListNode} *head
     * @param {int} left
     * @param {int} right
     * @return {*}
     */
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        ListNode *dummyHead = new ListNode(-1);
        dummyHead->next = head;
        ListNode *pre = dummyHead;
        for (int i = 0; i < left - 1; i++)
        {
            pre = pre->next;
        }
        ListNode *cur = pre->next;
        ListNode *next;
        for (int i = 0; i < right - left; ++i)// 这个需要遍历right-left, 因为还需要left 和 right 是需要反转链表的开始节点和结束节点。 所以如果cur开始遍历， 且cur 不会到right， 只有next到right
        {
            next = cur->next;
            cur->next = next->next;
            next->next = pre->next;
            pre->next = next;
        }
        return dummyHead->next;
    }
};


