/*
 * @Date: 2021-11-28 20:46:17
 * @LastEditors: kafier
 * @LastEditTime: 2021-11-28 20:53:20
 */

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#include <queue>
using namespace std;
class Solution
{
public:
    bool isSymmetric(TreeNode *root)
    {
        return judgeSame(root, root);
    }

    bool judgeSame(TreeNode *root1, TreeNode *root2)
    {
        queue<TreeNode*> q;
        q.push(root1);
        q.push(root2);
        while(!q.empty())
        {
            TreeNode* tmp1 = q.front();
            q.pop();
            TreeNode* tmp2 = q.front();
            q.pop();
            // 1.要考虑空指针情况， 但是队列不为空
            if(!tmp1 && !tmp2)
            {
                continue;
            }
            if(tmp1 && tmp2 && tmp1->val != tmp2->val){
                return false;
            }
            q.push(tmp1->left);
            q.push(tmp2->right);

            q.push(tmp1->right);
            q.push(tmp2->left);
        }
        return true;
    }
};