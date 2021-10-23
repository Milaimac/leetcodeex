// 236. 二叉树的最近公共祖先
// 要判断 二叉树的最近公共祖先， 那么公共祖先节点x必须满足以下条件，1. 左右子树需要包含p， q节点， 或者说祖先节点x是p或者q， 但是其中左右子树包含左右节点的其中一个 
// 判断条件 (f_lson && f_rson) || ((x==p ||x == q) && (f_lson || f_rson)) 
// f_lson 是 
#include <stdio.h>
#include <unordered_map>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
// 递归解法， 递归确认左右子树（本节点）是否为p 或者 q节点
// 如果有， true
// 最终判断是否存在父结点是否符合要求
// 要怎么判断是最近的。 满足左右子树分别拥有p和q，或者本身是p和q

// 时间复杂度为O(n)
// 空间复杂度为O(n)
public:
    TreeNode* ans;
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return ans;
    }


    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(root == nullptr)
            return false;
        bool lson = dfs(root->left, p, q);
        bool rson = dfs(root->right, p, q);
        if((lson && rson) || ((p == root || q == root) && (lson || rson)) )
        {
            ans = root;
            // return true;
        }
        // 只要确保左右子树其中有一个即可，或者该节点就是目标节点
        return (lson || rson || (root == p) || (root == q));
    }
};



class Solution1 {
public:
    // 另一种递归版本
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr)
            return root;
        // 通过该函数找到对应的p和q
        if(root->val == p->val || root->val == q->val)
            return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        // 如果该结点不是最近公共祖先， 那么它的左右子树必定找不到p和q
        // 所有必定在其中的一个子树
        if(left == nullptr)     return right;
        if(right == nullptr)    return left;
        return root;
    }
};

class Solution2
{
public:
    // 用哈希表存储所有节点的父结点， 然后我们可以利用节点的父结点信息从 p 节点开始不断往上跳， 并记录已经访问过的节点
    // 从p 节点不断往上移动， 并用数据结构记录已经访问的节点， 
    // 同样从q不断往上移动， 如果碰到已经记录的， 说明这就是。。 最近的祖先

    // 这个fa哈希表， 需要通过子节点的val来记录父结点
    unordered_map<int, TreeNode*> fa;
    unordered_map<int, bool> vis;

    void dfs(TreeNode* root)
    {
        if(root->left != nullptr)
        {
            fa[root->left->val] = root;
            dfs(root->left);
        }
        if(root->right != nullptr)
        {
            fa[root->right->val] = root; 
            dfs(root->right);
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        fa[root->val] = nullptr;
        dfs(root);
        while(p!=nullptr)
        {
            // 开始对哈希表的visit做记录
            vis[p->val] = true;
            p = fa[p->val];
        }
        while(q != nullptr)
        {
            if(vis[q->val])     return q;
            q = fa[q->val];
        }   
        return nullptr;
    }

};