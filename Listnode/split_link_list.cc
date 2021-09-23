// 725. 分隔链表

#include <vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* node = head;
        int count = 0;  // 不要忘记初始化
        while(node){
            node = node->next;
            ++count;
        }
        node = head;
        int num = count / k;            // 分隔为k份时， 多少是连接的
        int remainder = count % k;      // 剩余多少份， 如果不行，就用nullptr来凑
        vector<ListNode*> res(k, nullptr);
        ListNode* curr = head;
        for(int i = 0;i<k && curr != nullptr;++i){
            res[i] = curr;
            int partsize = num + (i < remainder ? 1 : 0);       // 对于这种用剩余remainder的情况，可以通过给
            for(int j = 1;j < partsize;++j){
                curr =  curr->next;
            }

            ListNode* next = curr->next;
            curr->next = nullptr;
            curr = next;
        }
        return res;
    }
};

// 链表的分隔