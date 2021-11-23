/*
 * @Date: 2021-11-22 17:51:11
 * @LastEditors: kafier
 * @LastEditTime: 2021-11-22 20:26:25
 */
#include <vector>
#include "generate_listNode.hpp"
#include <queue>
using namespace std;
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class Solution {
public:
    /**
     * @description:
     * 1. 按照顺序遍历的方法， 但是下面这种写法是不行的。 因为传入的是指针, 出了点bug ， 那就是mergeLists是返回cur->next， 没有返回dummhHead->next;
     * 这导致了结果不对
     * 2. 使用二分的思想去解决， 
     * @param {*}
     * @return {*}
     */
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int len = lists.size();
       
        ListNode* cur = nullptr;
        for(int i =0;i< len;++i){
            cur = mergeLists(cur, lists[i]);
        }
        return cur;
    }
    ListNode* mergeLists(ListNode* list1, ListNode* list2){
        // if(!list1 && !list2){
        //     return nullptr;
        // }
        ListNode* dummyhead = new ListNode();
        ListNode* curr = dummyhead;
        while(list1 && list2){
            if(list1->val <= list2->val){
                curr->next = list1;
                list1 = list1->next;
            }    
            else{
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next;
        }
        curr->next = list1 ? list1 : list2;
        return dummyhead->next;
    }
    
// 使用二分法，将k个数组分为2部分去合并
    ListNode* BinaryMerge(vector<ListNode*> &lists, int l, int r){
        if (l == r) return lists[1];
        if(l > r) return nullptr;
        int mid = (l + r) >> 1;
        return mergeLists(BinaryMerge(lists, l, mid) , BinaryMerge(lists, mid+1, r));
    }

    ListNode* mergeKLists1(vector<ListNode*> &lists){
        return BinaryMerge(lists, 0, lists.size() - 1);
    }

};

// 使用优先队列解决
class Solution1{
public:
    /**
     * @description:
     * 这个方法和之前不同， 这个需要维护每个链表没有合并的元素的最前面一个， k个链表就最多有k个满足这样条件的元素， 每次在这些元素里面选取val属性最小的元素合并到答案中。  
     * @param {*}
     * @return {*}
     */
    struct Status{
        int val; 
        ListNode* ptr;
        // 因为priority_queue默认是最大堆
        bool operator< (const Status& rhs) const{
            return val > rhs.val;
        }
    };

    priority_queue<Status> q;
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for(auto node:lists){
            if(node)    q.push({node->val, node});
        }
        ListNode head, *tail = &head;
        while(!q.empty()){
            auto f = q.top();
            q.pop();
            tail->next = f.ptr;
            tail = tail->next;
            if(f.ptr->next) q.push({f.ptr->next->val, f.ptr->next});
        }
        return head.next;
    }
};
int main(){
    vector<vector<int>> lists = {{1,4,5},{1,3,4},{2,6}};
    int len = lists.size();
    vector<GenerateListNode*> res(len);
    for(int i = 0;i < len;++i){
        res[i] = new GenerateListNode(lists[i]);
    }
    vector<ListNode*> listNodes(len);
    for(int i = 0;i < len;++i){
        listNodes[i] = res[i]->head();
    }
    
    Solution sl;
    sl.mergeKLists(listNodes);
    
}