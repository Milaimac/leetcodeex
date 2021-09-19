// 剑指offer32 从上到下打印二叉树
#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

class Solution{
public:
    vector<vector<int>> levelOrder(TreeNode* root){
        // queue<int> q;
        if(root == NULL)
        {
            return ret;
        }
        vector<int> init(1,root->val);
        ret.push_back(init);
        bfs(root, 1);
        return ret;

    }
// 错误解法
    void bfs(TreeNode* root, int depth){
        queue<TreeNode*> qq;
        vector<int> currentv;
        if(root == NULL){
            return;
        }
        qq.push(root);
        // pthread_mutex_lock RAII 
        // currentv.push_back(root->val);
        while(qq.empty()){
            TreeNode* temp = qq.front();
            if(depth%2 == 1){
                vector<int> subtree;
                subtree.push_back(temp->left->val);
                subtree.push_back(temp->right->val);
                ret.push_back(subtree);
                bfs(temp->left, depth+1);
                bfs(temp->right, depth+1);
            }
            else{
                vector<int> subtree;
                subtree.push_back(temp->right->val);
                subtree.push_back(temp->left->val);
                ret.push_back(subtree);
                bfs(temp->right, depth+1);
                bfs(temp->left, depth+1);
            }
        }
    }
private:
    vector<vector<int>> ret;
};

void constructTree(vector<int> treenode){
    for(auto& it:treenode){
        // TreeNode
    }
}


int main(){

}