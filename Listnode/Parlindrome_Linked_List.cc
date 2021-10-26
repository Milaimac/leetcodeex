#include <vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// 每次都不怎么记得住回文的定义。 大概是从前面往后念和从后往前念是一样的
// 既然是一样， 那么有 前半部分和后半部分是一样的

class Solution {
public:
    // 直接放到数组中， 如果是在数组判断回文， 直接双指针遍历即可
    bool isPalindrome(ListNode* head) {
        vector<int> vec;
        ListNode* dummy = head;
        while(dummy)
        {
            vec.push_back(dummy->val);
            dummy = dummy->next;
        }

        int left = 0, right = vec.size()-1;
        while(left <= right)
        {
            if(vec[left] != vec[right]){
                return false;
            }
            ++left;
            --right;
        }
        return true;
    }
};

// 要如何避免那多出来的空间复杂度呢？
// 也即是问如何直接操作链表， 避免开辟新的空间
// 要对链表进行比较， 不如将后半部分给反转， 而后比较是否是回文链表
// 1. 使用快慢指针找到中间节点， 
// 2. 反转后半部分链表， 
// 3. 比较
// 耦合奇偶性， 当有奇数， 应当把中间节点作为末尾， 这样比较的时候以一方为nullPtr为准
class Solution1{
public:
    bool isPalindrome(ListNode* head) {
        if(head == nullptr)
        {
            return true;
        }

        // 找到中间节点
        ListNode* firstHalfEnd = themiddleNode(head);
        ListNode* secondHalfStart = reverList(firstHalfEnd->next);

        // 判断是否为回文
        ListNode* p1 = head;
        ListNode* p2 = secondHalfStart;
        bool result = true;
        while(result && p2 != nullptr)
        {// 这时候只要判断后半部分的节点到达nullptr就行了
            if(p1->val != p2->val){
                return false;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        // firstHalfEnd->next = reverList(secondHalfStart);
        return result;

    }


    ListNode* reverList(ListNode* head)
    {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(curr)
        {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        // 返回的是反转后的头指针。 1-2-3-4 == 4-3-2-1
        return prev;
    }

    ListNode* themiddleNode(ListNode* head)
    {
        ListNode* low = head;
        ListNode* fast = head;
        while(fast->next != nullptr && fast->next->next != nullptr)
        {
            fast = fast->next->next;
            low = low->next;
        }
        return low;
    }
};
