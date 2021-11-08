/*
 * @Date: 2021-11-08 10:31:57
 * @LastEditors: kafier
 * @LastEditTime: 2021-11-08 11:31:55
 * @FilePath: /leetcodeex/codetop/哈希表/Binary_Tree_Inorder_Traversal.cc
 */

#include <vector>
#include <stack>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/**
 * @description: 二叉树的中序遍历
 *  先遍历左子节点 - 根节点 - 右节点
 *  直接使用递归的做法， 会到达O(n)的空间复杂度
 * @param {*}
 * @return {*}
 */
class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        dfs(root);
        return res;
    }

    void dfs(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }

        dfs(root->left);
        res.push_back(root->val);
        dfs(root->right);
    }

    vector<int> res;
    /**
 * @description:  熟悉一下迭代写法
 *  使用一个栈将
 * @param {*}
 * @return {*}
 */

    vector<int> inorderTraversal1(TreeNode *root)
    {
        vector<int> ret;
        stack<TreeNode *> stk;
        while(root != nullptr || !stk.empty()){
            while(root != nullptr){
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            ret.push_back(root->val);
            root = root->right;    
        }
        return ret;
    }
};


/**
 * @description: Morris 中序遍历法， 可以将空间复杂度降为 O(1)
 * 步骤如下
 *  1. 如果x没有左孩子， 将x的值加入答案数组， 再访问x的右孩子， 即x=x.right
 *  2. 如果x有左孩子， 找到x左子树上最右的节点（即左子树中序遍历的最后一个节点） 记为predecessor
 *      如果predecessor的右孩子为空，则将其右孩子指向x， 然后访问x的左孩子， x = x.left
 *      不为空， 那么其右孩子指向x， 说明我们已经遍历完了左子树（没有右孩子）
 * 
 *  3. 整个过程就多做了一步， 将x的左子树中最右边的节点的右孩子指向x， 这样在左子树遍历完成后我们通过这个指向走回了x
 * @param {*}
 * @return {*}
 */
class Solution1 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode *predecessor = nullptr;

        while (root != nullptr) {
            if (root->left != nullptr) {
                // predecessor 节点就是当前 root 节点向左走一步，然后一直向右走至无法走为止
                predecessor = root->left;
                while (predecessor->right != nullptr && predecessor->right != root) {
                    predecessor = predecessor->right;
                }
                
                // 让 predecessor 的右指针指向 root，继续遍历左子树
                if (predecessor->right == nullptr) {
                    predecessor->right = root;
                    root = root->left;
                }
                // 说明左子树已经访问完了，我们需要断开链接
                else {
                    res.push_back(root->val);
                    predecessor->right = nullptr;
                    root = root->right;
                }
            }
            // 如果没有左孩子，则直接访问右孩子
            else {
                res.push_back(root->val);
                root = root->right;
            }
        }
        return res;
    }
};
