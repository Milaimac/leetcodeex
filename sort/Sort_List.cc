
#include <vector>
#include <iostream>
using namespace std;

// class CreateList;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 如何给链表进行排序

// 使用归并排序

// 常用的O(nlog(n))的排序算法， 有归并排序， 快速排序， 堆排序

// 这里采用自顶向下的归并排序
// 时间复杂度为 O(n log(n))
// 
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        return sortList(head, nullptr);
    }

    ListNode* sortList(ListNode* head, ListNode* tail)
    {
        if(head == nullptr)
        {
            return head;
        }
        if(head->next == tail)
        {
            head->next = nullptr;
            return head;
        }

        ListNode* slow = head, *fast = head;
        while(fast != tail)
        {   // one loop, fast go two step
            slow = slow->next;
            fast = fast->next;
            if(fast != tail)
            {
                fast = fast->next;
            }
        }
        ListNode* mid = slow;

        return merge(sortList(head, mid), sortList(mid, tail));
    }

    ListNode* merge(ListNode* head1, ListNode* head2)
    {
        ListNode* dummy = new ListNode(0);      //创建个虚指针， 作为头指针的prev
        ListNode* temp = dummy, *temp1 = head1, *temp2 = head2;
        while(temp1 != nullptr && temp2 != nullptr)
        {
            if(temp1->val <= temp2->val)
            {
                temp->next = temp1;
                // temp1->next = temp2;
                temp1 = temp1->next;
            }
            else
            {
                temp->next = temp2;
                // temp2->next = temp1;
                temp2 = temp2->next;
            }
            temp = temp->next;
        }
        if(temp1 != nullptr)
        {
            temp->next = temp1;
        }
        else if(temp2 != nullptr)
        {
            temp->next = temp2;
        }

        return dummy->next;
    }
};
class CreateList{
public:
    CreateList(vector<int>& vec):vec_(vec){
        generateList();
    }
    CreateList(ListNode* head):head_(head)
    {

    }
    ListNode* generateList()
    {
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;
        for(auto& ele:vec_)
        {
            temp->next = new ListNode(ele);
            temp = temp->next;
        }
        head_ = dummy->next;
        return dummy->next;
    }

    void printList()
    {
        ListNode* head = head_;
        // ListNode* temp = head;
        while(head != nullptr)
        {
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    }
    
private:
    vector<int> vec_;
    ListNode* head_;
};
// 自底向上归并排序
// 具体做法
// 1. 用subLength表示每次需要排序的子链表的长度， 初始时， sublength=1；
// 2. 每次将链表拆分为若干个长度为subLength的子链表， 最后一个子链表的长度可以小于subLength， 按照两个子链表一组可以进行合并， 合并后即可得到若干个长度为subLength x 2的有序子链表
class SolutionV1 {
public:
    ListNode* sortList(ListNode* head) {
        if(head == nullptr)
        {
            return head;
        }

        int lenght = 0;
        ListNode* node = head;
        // 计算处链表长度
        while(node)
        {
            lenght++;
            node = node->next;
        }
        ListNode* dummyhead = new ListNode(0, head);
        // 将subLength 不断扩大
        for(int subLength = 1; subLength < lenght; subLength <<= 1)
        {
            //在每次扩充的时候， 必须确保从头开始
            ListNode* prev = dummyhead, *curr = dummyhead->next;
            while(curr != nullptr)
            {
                ListNode* head1 = curr;
                // 将前subLength的链表给独立起来， 同时得到下一个长度为subLenght的链表的头指针head2， 
                for(int i = 1;i < subLength && curr->next != nullptr;++i)
                {
                    curr = curr->next;
                }
                ListNode* head2 = curr->next;
                // CreateList printHead2(head2);
                // printHead2.printList();
                // cout << endl;
                curr->next = nullptr;   // FIXME 这个有什么用？ debug 发现这个是将前一个subLength的链表设置好长度   
                curr = head2;
                // CreateList print(curr);
                // print.printList();
                for(int i = 1;i < subLength && curr != nullptr && curr->next != nullptr;++i)
                {
                    curr = curr->next;
                }
                ListNode* next = nullptr;       //将它设置为长度subLength的链表， 将curr->next = nullptr
                if(curr != nullptr)
                {
                    next = curr->next;
                    curr->next = nullptr;
                }

                ListNode* merged = merge(head1, head2);
                prev->next = merged;
                while(prev->next != nullptr)
                {
                    prev = prev->next;
                }

                curr = next;

            }
        }
        return dummyhead->next;
    }

    ListNode* merge(ListNode* head1, ListNode* head2)
    {
        ListNode* dummyHead = new ListNode(0);
        ListNode* temp = dummyHead, *temp1 = head1, *temp2 = head2;
        while(temp1 != nullptr && temp2 != nullptr)
        {
            // 归并排序， 如果一个数组的元素比另外一个小， 那么继续遍历整个数组
            if(temp1->val <= temp2->val)
            {
                temp->next = temp1;
                temp1 = temp1->next;
            }
            else if(temp1->val > temp2->val)
            {
                temp->next = temp2;
                temp2 = temp2->next;
            }
            temp = temp->next;
        }

        if(temp1 != nullptr)
        {
            temp->next = temp1;
        }
        else if(temp2 != nullptr)
        {
            temp->next = temp2;
        }
        return dummyHead->next;

    }
};





int main()
{
    vector<int> vec = {-1,5,4,3,0};
    CreateList list(vec);
    ListNode* head = list.generateList();
    SolutionV1 sl;
    ListNode* res =  sl.sortList(head);
    CreateList res1(res);
    res1.printList();

    // ListNode* curr = new ListNode(2);
    // curr->next = new ListNode(3);
    // vector<int> vec = {22,44};
    // CreateList list(vec);
    // curr = list.generateList();
    // while (curr != nullptr)
    // {
    //     /* code */
    //     cout << curr->val << " ";
    //     curr = curr->next;
    // }
    // cout << endl;
    
}