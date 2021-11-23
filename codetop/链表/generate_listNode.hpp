/*
 * @Date: 2021-11-22 17:58:34
 * @LastEditors: kafier
 * @LastEditTime: 2021-11-22 19:53:12
 */

#include <vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class GenerateListNode{
public:
    GenerateListNode(vector<int> vec){
        int len = vec.size();
        ListNode* curr = list;
        for(int i = 0;i < len;++i){
            curr->next = new ListNode(vec[i]);
            curr = curr->next;
        }
    }
    ListNode* head(){
        return list->next;
    }
private:
    ListNode* list = new ListNode(0);
};