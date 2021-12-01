/*
 * @Date: 2021-11-25 19:18:53
 * @LastEditors: kafier
 * @LastEditTime: 2021-11-26 22:07:47
 */

#include <vector>
#include <queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


// 返回每一层中最右的节点， 然而并不是， 如果没有右子节点， 但是有左子节点， 照样需要左子节点的视图
// 如果右子节点没有子孙了，但是左子节点还有， 要能够做到回去遍历左子节点。 
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root){
            return res;
        }
        res.push_back(root->val);
        dfs(root);
        return res;
    }
    // 为了解决这个问题， 每一层才push 进vector里面
    void dfs(TreeNode* root){
        if(!root){
            return;
        }
        if(root->right){ 
            res.push_back(root->right->val);
            dfs(root->right); //这种写法没法考虑当右节点无了， 但是左节点还在的情况。 
        }
        else if(root->left){ // 这种写法也无法满足所有情况
            res.push_back(root->left->val);
            dfs(root->left); 
        } 
    }
private:
    vector<int> res;
};
class Solution2 {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root){
            return res;
        }
        res.push_back(root->val);
        dfs(root, 0);
        return res;
    }
    // 为了解决这个问题， 每一层才push 进vector里面
    void dfs(TreeNode* root, int level){
        if(!root){
            return;
        }
        
        if(root->left)  dfs(root->left, level+1);
        if(root->right) dfs(root->right, level+1);
        if(level <= res.size()-1){
            res[level] = root->val;
        }
        else{
            res.push_back(root->val);
        }
    }
private:
    vector<int> res;
};




// 试试看使用层序遍历来解决这个问题
class Solution1{
public:
    vector<int> rightSiedView(TreeNode* root){
        if(!root){
                      
        }
        
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            if(temp->left)      q.push(temp->left);
            if(temp->right){
                q.push(temp->right);
                // 这种写法会把所有的右节点都放进去'
                if(!root->right)
                    res.push_back(temp->right->val);
            }
        }      
    }
private:
    vector<int> res;
};