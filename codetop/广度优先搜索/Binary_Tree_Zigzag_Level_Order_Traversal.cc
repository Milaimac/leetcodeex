/*
 * @Date: 2021-11-28 20:30:23
 * @LastEditors: kafier
 * @LastEditTime: 2021-11-28 20:40:28
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    /**
     * @description:
     * 和那个需要存储数组的类型差不多，我们只要在push到vector的时候进行修改就okl
     * 但是queue的不需要进行修改 
     * @param {TreeNode*} root
     * @return {*}
     */
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == nullptr)
        {
            return vector<vector<int>> ();
        }

        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);
        int flag = 1; //设第一个为1
        // res.push_back(vector<int>());
        while(!q.empty())
        {
            deque<int> levelList;
            int levelsize = q.size();
            for(int i = 0;i < levelsize;++i)
            {
                auto node = q.front();
                q.pop();
                if(flag)
                {
                    //从左到右
                    levelList.push_back(node->val);
                }                
                else{
                    levelList.push_front(node->val);
                }

                if(node->left)
                    q.push(node->left);

                if(node->right)
                    q.push(node->right);
            }
            res.emplace_back(vector<int>{levelList.begin(), levelList.end()});
            flag = !flag;
        }
        return res;   
    }
};