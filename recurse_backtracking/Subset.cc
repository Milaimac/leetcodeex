// 78. 子集
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> ret;
    vector<int> path;
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(0, nums);
        return ret;
    }

    void dfs(int curr, vector<int>& nums){
        if(curr == nums.size()){
            ret.push_back(path);
            return;
        }
        // 跳过
        dfs(curr+1, nums);
        path.push_back(nums[curr]);
        dfs(curr+1, nums);
        path.pop_back();
        
    }
};