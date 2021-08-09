/*
给定一个单链表 L：L0→L1→…→Ln-1→Ln ，
将其重新排列后变为： L0→Ln→L1→Ln-1→L2→Ln-2→…
*/
#include"head.h"
class Solution {
public:
    //用线性表存储结构，在从左端点和右端点进行交替排序  
    void reorderList_1 (ListNode *head) {
        //由于head不支持下标访问，所以用线性表存储
        if(head == nullptr){
            return ;
        }
        vector<ListNode*> vec;
        ListNode* node = head;
        while(node != nullptr){
            vec.emplace_back(node);
            node = node->next;
        }
        int i=0, j=vec.size()-1;
        while(i<j){
            vec[i]->next = vec[j];
            i++;
            if(i == j){
                break;
            }
            vec[j]->next = vec[j];
            j--;
        }
        vec[i]->next = nullptr;
    }

/*
注意到目标链表即为将原链表的左半端和反转后的右半端合并后的结果。

这样我们的任务即可划分为三步：

    找到原链表的中点（参考「876. 链表的中间结点」）。
        我们可以使用快慢指针来 O(N)O(N)O(N) 地找到链表的中间节点。

    将原链表的右半端反转（参考「206. 反转链表」）。
        我们可以使用迭代法实现链表的反转。

    将原链表的两端合并。
        因为两链表长度相差不超过 111，因此直接合并即可。
*/
    void reorderList_2(ListNode* head){
        if(head == nullptr){
            return;
        }
        ListNode* mid = middleNode(head);
        ListNode* l1 = head;
        ListNode* l2 = mid->next;
        mid->next = nullptr;
        l2  = reverList(l2);
        mergeList(l1, l2);
    }

    ListNode* middleNode(ListNode* head){
        // 使用快慢指针，fast走两步，当fast到终点，这时候slow到中点
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* reverList(ListNode* head){
        // 反转以head开头的链表， 注意反转链表的核心就是创建一个prev
        ListNode* prev = nullptr;
        ListNode* cur = head;
        while(cur != nullptr){
            ListNode* nextTemp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nextTemp;
        }
        // return head;
        return prev;
    }
    // 将中点右边的链表反转后进行merge
    //因为是对半分的，没必要求考虑两个链表长度不同的情况
    void mergeList(ListNode* l1, ListNode* l2){
        ListNode* l1_tmp;
        ListNode* l2_tmp;

        while(l1 && l2 ){
            l1_tmp = l1->next;
            l2_tmp = l2->next;

            l1->next = l2;
            l1 = l1_tmp;
            l2->next = l1;
            l2 = l2_tmp;
        }
    }
};

