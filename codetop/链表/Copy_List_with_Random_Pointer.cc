/*
 * @Date: 2021-12-04 23:16:02
 * @LastEditors: kafier
 * @LastEditTime: 2021-12-05 17:59:26
 */
#include <stdio.h>
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

#include <unordered_map>
using namespace std;
class Solution {
public:
    /**
     * @description: 
     * 本题中因为随机节点的存在， 当我们在拷贝节点时， 【当前节点的随机指针指向的节点】可能还没有创建， 我们可以利用回溯的方式， 让每个节点的拷贝操作相互独立。
     * 对于当前节点， 我们首先要进行拷贝， 然后进行【当前节点的后继节点】 和 【当前节点的随机指针指向的节点】拷贝。 拷贝完成后将创建的新节点的指针返回， 即可完成当前节点的两指针的复制
     * 我们使用哈希表记录每个节点对应新节点的创建情况。 
     * 如果这两个节点中的任何一个节点的新节点没有被创建，我们都立刻递归地进行创建
     * @param {Node*} head
     * @return {*}
     */
    unordered_map<Node*, Node*> cacheNode;
    Node* copyRandomList(Node* head) {
        if(head == nullptr)
        {
            return nullptr;
        }
        if(!cacheNode.count(head)){
            Node* headNew = new Node(head->val);
            cacheNode[head] = headNew;
            headNew->next = copyRandomList(head->next);
            headNew->random = copyRandomList(head->random);
        }

        return cacheNode[head];
    }


};


class Solution1 {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr)
        {
            return nullptr;
        }
        // 将拷贝链表安插在原链表李米娜
        for(Node* node = head;node != nullptr; node = node->next->next)
        {
            Node* nodeNew = new Node(node->val);
            nodeNew->next = node->next;
            node->next = nodeNew;
        }
        // 设置拷贝链表的随机节点
        for(Node* node = head; node != nullptr;node = node->next->next)
        {
            Node* nodeNew = node->next;
            nodeNew->random = (node->random != nullptr) ? node->random->next : nullptr;
        }
        // 将拷贝链表和原链表进行分离， 因为分离后的秩序回来了， 所以使用的遍历是 node = node->next
        Node* headNew = head->next;
        for(Node *node= head;node!= nullptr;node = node->next){
            Node* nodeNew = node->next;
            node->next = node->next->next;
            nodeNew->next = (nodeNew->next != nullptr ) ? nodeNew->next->next : nullptr;
        }
        return headNew;
    }
};

