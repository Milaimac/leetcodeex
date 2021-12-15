/*
 * @Date: 2021-12-12 14:42:28
 * @LastEditors: kafier
 * @LastEditTime: 2021-12-12 15:06:22
 */
#include <vector>
#include <iostream>
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
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        ListNode *dummyhead = new ListNode(-1, head);
        // ListNode *cur = head;
        ListNode* dummyhead1 = head;
        for (int i = 1; i < left-1; ++i)
        {
            dummyhead1 = dummyhead1->next;
        }
        ListNode* cur = dummyhead1->next;
        // cout << cur->val << endl;
        ListNode *tail = cur;
        for (int i = left; i < right; ++i)
        {
            tail = tail->next;
        }
        ListNode *pre = tail->next;
        while (pre != tail)
        {
            ListNode *next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        dummyhead1->next = pre;
        return dummyhead->next;
    }
};

int main()
{
    vector<int> vec = {1, 2, 3, 4, 5};
    ListNode head(vec[0]);
    ListNode *cur = &head;
    for (int i = 1; i < vec.size(); ++i)
    {
        cur->next = new ListNode(vec[i]);
        cur = cur->next;
    }

    Solution sl;
    sl.reverseBetween(&head, 2, 4);
}