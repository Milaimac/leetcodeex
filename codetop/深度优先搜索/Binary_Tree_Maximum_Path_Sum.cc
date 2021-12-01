/*
 * @Date: 2021-11-28 20:00:28
 * @LastEditors: kafier
 * @LastEditTime: 2021-11-28 20:09:13
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#include <limits.h>
#include <algorithm>
using namespace std;
class Solution {
public:
    /**
     * @description: 
     *  从任意节点出发， 同一节点只出现一次， 不一定经过根节点。 
     *  可以计算每个节点和其子节点中的最大贡献值之和。 （对于叶节点就是自己） 但是最终要返回的答案是可以更新的
     * @param {TreeNode*} root
     * @return {*}
     */
    
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return ans;
    }

    int dfs(TreeNode* root){
        if(root == nullptr){
            return 0;
        }

        int leftgain = max(dfs(root->left), 0);
        int rightgain = max(dfs(root->right), 0);
        
        int thenodegain = root->val + leftgain + rightgain;
        ans = max(thenodegain, ans);
        // 这个所谓的最大贡献值， 是只能够设置其中左右子节点的其中一个， 因为不是以它为根节点
        return root->val + max(leftgain, rightgain);  
    }
private:
    int ans = INT_MIN;
};