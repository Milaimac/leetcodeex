/*
 * @Date: 2021-12-04 19:36:51
 * @LastEditors: kafier
 * @LastEditTime: 2021-12-04 19:41:39
 */

#include <stdio.h>
class Node {
public:
    int val;
    Node* left;
    Node* right;

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

class Solution {
public:
    /**
     * @description: 
     * 要组成一个排序链表， 那么必须要中序遍历
     * @param {Node*} root
     * @return {*}
     */    
    Node* pre = nullptr, *head = nullptr;
    Node* treeToDoublyList(Node* root) {
        if(!root)   return root;
        dfs(root);
        head->left = pre;
        pre->right = head;
        return head;
    }

    void dfs(Node* root){
        if(root == nullptr) return;
        dfs(root->left);
        if(pre) pre->right = root;
        else head = root;
        root->left = pre;
        pre = root;
        dfs(root->right);
        
    }
};