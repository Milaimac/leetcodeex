// 剑指 Offer 36. 二叉搜索树与双向链表

#include<iostream>
using namespace std;
class Node {
public:
    int val;
    Node* left;     //Node* pre
    Node* right;    //Node* right

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
// 中序遍历
// 设置前驱节点pre和当前节点
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if(root == nullptr){
            return nullptr;
        }
        dfs(root);
        head->left = pre;
        pre->right = head;
        return head;
    }
private:
    Node *pre, *head;
    void dfs(Node* cur){
        if(cur == nullptr)
            return;
        dfs(cur->left);
        if(pre != nullptr) pre->right = cur;
        else head = cur;

        cur->left = pre;
        pre = cur;
        dfs(cur->right);
    }
};