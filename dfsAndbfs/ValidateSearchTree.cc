// 98. 验证二叉搜索树

// 中序遍历，将数据放进内存 -- 不切实际。

// 但是递归也会使用到堆上的内存
#include<iostream>
#include<stack>
#include <limits.h>
using namespace std;
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
        stack<TreeNode*> stk;
        long long inorder =  LONG_LONG_MIN-1;  
        while(root != nullptr || !stk.empty()){
            // 需要将树的左子节点全先压到栈
            while(root){
                stk.push(root);
                root = root->left;
            }
            // 现在stk.top()为最left
            root = stk.top();
            stk.pop();
            if(root->val <= inorder){
                return false;
            }
            inorder = root->val;
            root = root->right;
        }
        return true;
    }

    // 现在来思考一下 递归到底怎么解决
};

class SolutionV1{
public:
    long long minm = LONG_LONG_MIN;
    long long maxm = LONG_LONG_MAX;
    bool isValidBST(TreeNode* root) {
        return dfs(root, minm, maxm);
    }
    bool dfs(TreeNode* root, long long lower, long long upper){
        if(root == nullptr){
            return true;
        }
        if(root->val < lower || root->val > upper){
            return false;
        }
        return dfs(root->left, lower, root->val) && dfs(root->right, root->val, upper);
    }    
};