#include"head.h"
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
private:
    unordered_map<int, int> index;
public:
    TreeNode* mybuildTree(const vector<int>& preorder,const vector<int>& inorder,int preorder_left,int preorder_right,int inorder_left, int inorder_right){
        if(preorder_left>preorder_right){
            return nullptr;
        }
        //先序遍历的第一个是根节点
        int preorder_root = preorder_left;
        //在中序遍历序列中寻找根节点的位置
        int inorder_root = index[preorder[preorder_root]]; //postition
        TreeNode* root = new TreeNode(preorder[preorder_root]); 
        //得到左子树的结点大小
        int size_left_subtree = inorder_root - inorder_left;
        //用递归求出左右子树
        root->left = mybuildTree(preorder,inorder,preorder_left+1,preorder_left+size_left_subtree,inorder_left,inorder_root-1);
        root->right = mybuildTree(preorder,inorder,preorder_left+size_left_subtree+1,preorder_right,inorder_root+1,inorder_right);
        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        for(int i = 0;i < n;i++){
            index[inorder[i]] = i;
        }
        return mybuildTree(preorder,inorder,0,n-1,0,n-1);
    }

};
