/*
 * @Date: 2021-11-28 20:20:44
 * @LastEditors: kafier
 * @LastEditTime: 2021-11-28 20:29:39
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

class Solution {
public:
    /**
     * @description: 
     * 和普通的bfs不同的是， 我们需要将每一层的数据存储到数组中。 
     * 我们可以利用队列大小， 表示每一层。 从而达到存储目的
     * @param {TreeNode*} root
     * @return {*}
     */
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr)
        {
            return vector<vector<int>> ();
        }

        vector<vector<int>> ret;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int currentsize = q.size();   
            ret.push_back(vector<int>());
            for(int i = 0;i<currentsize;++i)
            {
                auto node = q.front();
                q.pop();
                ret.back().push_back(node->val);
                if(node->left)  q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        return ret;
    }  
};