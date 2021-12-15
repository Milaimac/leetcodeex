/*
 * @Date: 2021-12-01 21:37:58
 * @LastEditors: kafier
 * @LastEditTime: 2021-12-01 22:47:47
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        return dfs(root);
    }

    TreeNode* dfs(TreeNode* root){
        if(root == nullptr){
            return nullptr;
        }
        TreeNode* left = dfs(root->left);
        TreeNode* right = dfs(root->right);
        root->left = right;
        root->right = left;
        return root;
    }
};