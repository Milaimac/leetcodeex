// 剑指 Offer 68 - I. 二叉搜索树的最近公共祖先
#include <iostream>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* Ancestor = root;
        while(Ancestor){
            if(Ancestor->val > p->val && Ancestor->val > q->val){
                // 当前节点大于p和q，在左子树
                Ancestor = Ancestor->left;
            }
            else if(Ancestor->val < p->val && Ancestor->val < q->val){
                Ancestor = Ancestor->right;
            }
            else{
                break;
            }
        }
        return Ancestor;
    }
};