#include <iostream>
#include <queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


// 翻转二叉树——如果使用bfs， 
class Solution {
public:
    // 直接递归， 
    // 在递归的时候进行翻转
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr)
        {
            return root;
        }
        TreeNode* left = invertTree(root->left);
        TreeNode* right = invertTree(root->right);
        root->right = left;
        root->left = right;
        return root;
    }

    
};