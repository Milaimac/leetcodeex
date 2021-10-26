#include <algorithm>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


 // 需要求解出树的最大路径
class Solution {
public:
    // 找到左子树的最大深度和右子树的最大深度， l+r-1
    int ans;
    int depth(TreeNode* rt)
    {
        if(rt == nullptr){
            return 0;
        }
        int L = depth(rt->left);
        int R = depth(rt->right);
        ans = max(ans, L+R+1);
        return max(L, R)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        ans = 1;
        depth(root);
        return ans-1;
    }
};