#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
// 这么做是错的
class Solution {
public:
    //既然不给选重样的，那搞个数组标记一下啊
    void dfs(vector<vector<int>> &ret, vector<int>& candidates, vector<int> path, int target, int idx, vector<int> vis){
        if(target == 0){
            ret.push_back(path);
            return;
        }
        if(idx >= candidates.size() || target < 0){
            return;
        }
        // 跳过，不选择当前这个数
        dfs(ret, candidates, path, target, idx+1, vis);
        if(target-candidates[idx] >=  0 && !vis[idx]){ 
            path.push_back(candidates[idx]);
            //如果选了这个数，标记为1;，下次遇到直接跳过
            vis[idx] = 1;
            dfs(ret, candidates, path, target-candidates[idx], idx, vis);
            vis[idx] = 0;
            path.pop_back();
        }
        else{
            //既然标记过，直接跳过
            dfs(ret, candidates, path, target, idx+1, vis);
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> path;
        vector<int> vis(candidates.size(), 0);
        // vector<int> vis(0, candidates.size());
        dfs(res, candidates, path, target, 0, vis);
        return res;

    }
};

int main(){
    vector<int> candidates = {10,1,2,7,6,1,5};
    int target = 8;

    Solution sl;
    vector<vector<int>> res;
    res =  sl.combinationSum2(candidates, target);
    cout << "[" << endl;
    for(auto &ve:res){
        cout << "[";
        for(auto &ele:ve){
            cout<< ele << " ";
        }
        cout << "]" << endl;
    }
    cout << "]" << endl;
}

