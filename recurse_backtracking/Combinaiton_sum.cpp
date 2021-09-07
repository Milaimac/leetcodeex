// 39. 组合总和
#include<vector>
using namespace std;

class Solution {
public:
    void dfs(vector<int>& candidates, int target, int idx,vector<int>& path, vector<vector<int>> &ans){
        if(idx == candidates.size() || target < 0){
            return ;
        }
        if(target == 0){
            ans.push_back(path);
            return;
        }
        // 直接跳过
        dfs(candidates, target, idx+1, path, ans);
        if(target - candidates[idx] >= 0){
            path.push_back(candidates[idx]);
            dfs(candidates, target-candidates[idx], idx, path, ans);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> initpath;
        dfs(candidates, target, 0,initpath, res);
        return res;
    }
};