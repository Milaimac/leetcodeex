#include<unordered_map>
using namespace std;
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> m;
        Node* cur = head;
        if(head == nullptr){
            return nullptr;
        }
        while(cur!=nullptr){
            m[cur] = new Node(cur->val);
            cur = cur->next;
        }

        cur = head;
        while(cur != nullptr){
            m[cur]->next = cur->next;
            m[cur]->random = cur->random;// 如果是这样的话，就等于没有copy，而是将原来的指针传给它了而已。
            cur = cur->next;
        }
        return m[head];
    }
};