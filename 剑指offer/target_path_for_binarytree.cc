#include <vector>
#include <string>
#include <deque>
using namespace std;
// 112. 路径总和
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
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        vector<int> path;
        dfs(root, target, path);
        return res;
    }

    void dfs(TreeNode* root, int target, vector<int> path){
        if(target == 0){
            res.push_back(path);
            return ;
        }
        if( root == nullptr || target < root->val ){
            return;
        }
        path.push_back(root->val);
        dfs(root->left, target-root->val, path);
        dfs(root->right, target-root->val, path);
    }
    TreeNode* consturctbinarytree(vector<int> array){
        // 好吧，我真的不知道如何在C++实现一个代替null的情况，所以先用-1表示null吧
        if(array[0] == -1 || array.size() == 0){
            return  nullptr;
        }

        int index = 0;
        int len = array.size();

        TreeNode* root = new TreeNode(array[0]);

    
    }
private:
    vector<vector<int>> res;
};

int main(){
    TreeNode* root;
    
}