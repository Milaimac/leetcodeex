/*
 * @Date: 2021-11-27 13:15:11
 * @LastEditors: kafier
 * @LastEditTime: 2021-11-27 13:38:01
 */
#include <vector>
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
    //要求是找到对应的路径， 相对于路径总和 1（只要求判断是否有满足路径的）
    // 这个需要使用到回溯
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root, targetSum);
        return res;
    }

    void dfs(TreeNode* root, int targetsum){
        if(root == nullptr){
            return;
        }

        path.emplace_back(root->val);
        targetsum -= root->val;
        if(root->left == nullptr && root->right == nullptr && targetsum == 0)
        {
            // 能够达到条件的， 必须是子节点
            res.emplace_back(path);
        }
        dfs(root->left, targetsum);
        dfs(root->right, targetsum);
        path.pop_back();
        
    }

private:
    vector<vector<int>> res;
    vector<int> path;
};