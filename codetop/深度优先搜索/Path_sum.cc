/*
 * @Date: 2021-11-27 13:06:09
 * @LastEditors: kafier
 * @LastEditTime: 2021-11-27 13:15:00
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
    bool hasPathSum(TreeNode* root, int targetSum) {
        // 判断特殊条件
        if(!root){
            return  false;
        }

        if(root->left == nullptr && root->right == nullptr){
            return targetSum == root->val;
        }
        return  hasPathSum(root->left, targetSum- root->val) && hasPathSum(root->right, targetSum-root->val);
    }
};