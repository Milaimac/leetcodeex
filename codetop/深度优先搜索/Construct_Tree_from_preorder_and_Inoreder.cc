/*
 * @Date: 2021-11-26 22:27:05
 * @LastEditors: kafier
 * @LastEditTime: 2021-11-26 23:13:02
 */
#include <vector>
#include <unordered_map>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


// 从前序遍历和中序遍历构造二叉树， 
// 前序遍历  左  右 中，可以说前序遍历的第一个就是根节点， 我们按照先序遍历的顺序去构造二叉树
// 中序遍历  左 中 右
// 构建一个哈希表， 存储中序遍历中各个节点的位置
class Solution {
public:
    unordered_map<int ,int> index;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        // 建立中序遍历 相反的键值对
        for(int i = 0;i < n;++i){
            index[inorder[i]] = i;
        }
        return myBuild(preorder, inorder, 0, n-1, 0, n-1);
    }

    TreeNode* myBuild(vector<int>& preorder, vector<int>& inorder, int preorder_left, int preorder_right, int inorder_left, int inorder_right){
        if(preorder_left > preorder_right){
            return nullptr;
        }
        int preorder_root = preorder_left;
        int inorder_root = index[preorder[preorder_root]];      //找到中序遍历数组中，对应的根节点
        TreeNode* root = new TreeNode(preorder[preorder_root]);
        int size_left = inorder_root - inorder_left;
        root->left = myBuild(preorder, inorder, preorder_left + 1, preorder_left + size_left, inorder_left, inorder_root-1);
        root->right = myBuild(preorder, inorder, preorder_left+size_left + 1, preorder_right, inorder_root+1, inorder_right);
        return root;
    }
    
};