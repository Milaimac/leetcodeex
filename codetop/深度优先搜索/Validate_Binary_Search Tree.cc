/*
 * @Date: 2021-11-27 15:08:41
 * @LastEditors: kafier
 * @LastEditTime: 2021-11-27 15:54:36
 */
#include <limits.h>

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
    bool isValidBST(TreeNode* root) {
        return dfs(root, LONG_MIN, LONG_MAX);
    }

    bool dfs(TreeNode* root, long long lower, long long higher){
        if(root == nullptr){
            return true;
        }
        if(root->val <= lower || root->val >= higher){
            return false;
        }
        return  dfs(root->left, lower, root->val) && dfs(root->right, root->val, higher);
    }
};