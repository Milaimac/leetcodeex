/*
 * @Date: 2021-11-20 14:28:14
 * @LastEditors: kafier
 * @LastEditTime: 2021-11-21 08:16:11
 */


#include <vector>
using namespace std;

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
     * 直接将链表存入数组中， 而后通过规律进行重排。 
     * @param {ListNode} *head
     * @return {*}
     */
    void reorderList(ListNode *head)
    {
        vector<ListNode *> vec;
        ListNode *node = head;
        while (node)
        {
            vec.emplace_back(node);
            node = node->next;
        }

        int i = 0, j = vec.size() - 1;
        while (i < j)
        {
            vec[i]->next = vec[j];
            ++i;
            if(i == j)
                break;
            vec[j]->next = vec[i];
            --j;
        }

        vec[i]->next = nullptr;
    }
};


class Solution1
{
public:
    /**
     * @description: 
     * 1. 找到原链表的中点， 使用快慢指针来找到中间节点
     * 2. 将原链表的右半部分反转。 
     * 3. 将原链表的两端进行合并
     * @param {ListNode*} head
     * @return {*}
     */
    void reorderList(ListNode* head)
    {
        if(head == nullptr)
        {
            return;
        }

        ListNode* mid = middleNode(head);
        ListNode* l1 = head;
        ListNode* l2 = mid;
        mid = nullptr;          //为什么要把这个设置为nullptr？ 
        l2 = reverseList(l2);
        mergeList(l1, l2);
    }
    // 1, 找中间节点， 快指针走两步， 慢指针走一步， 当快指针为nullptr的时候， 慢指针到达中间节点。 对于是偶数个节点的链表， slow会停在左半部分
    ListNode* middleNode(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next !=  nullptr && fast->next->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* reverseList(ListNode* head)
    {
        ListNode* prev = nullptr;
        ListNode* cur = head;
        while(cur)
        {
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev->next;
    // 这里有变， 注意
    // 原答案后面赋值是将另外一个节点设为返回值的下一个节点， 所以结果一致。 
    }

    void mergeList(ListNode* head1, ListNode *head2)
    {
        ListNode* tmp1 = head1;
        ListNode* tmp2 = head2;
        while(head1 && head2)
        {
            tmp1 = head1->next;
            tmp2 = head2->next;

            head1->next = head2;
            head1 = tmp1;

            head2->next = head1;
            head2 = tmp2;
        }
    }


};