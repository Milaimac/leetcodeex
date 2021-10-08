// 47. 全排列 II
#include<vector>
#include<algorithm>
#include<set>
#include<iostream>
using namespace std;

// 回溯的三要素
// 选择列表，撤回操作，已经走过的路径，层次（步数） 


class Solution_err {
// 当时想的是，把重复的数给排除掉就可以了，可是这样遍历的时候就会导致dfs后续的步骤出错

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        set<int> quchong;
        for(auto &it:nums){
            quchong.insert(it);
        }
        int len = quchong.size();
        // sort(nums.begin(), nums.end());
        // vector<vector<int>> res;
        // vector<bool> used = {false};
        vector<bool> used(len, false);
        vector<int> path;

        dfs(quchong, 0, len, used, path, res);

        return res;
    }

private:        
    void dfs(set<int>& nums, int depth, int len, vector<bool> used, vector<int> path, vector<vector<int>> &res){
        if(depth == len){
            res.push_back(path);
            return;
        }
        
        for(auto it:nums){
            if(!used[it]){
                path.push_back(it);
                used[it] = true;
                dfs(nums, depth+1, len, used, path, res);

                used[it ]  = false;
                path.pop_back();
            }
        }

            
    }
    
};

// 那么把原先的去重组成一个数组，然后dfs时，用 原数组。
// 但是最后一步的回溯没法这么做， 并且这种只把第一步的重复数字给去除掉的方法，只能限定于重复数字只有两个的情况
// 最终办法，设置给记忆数组，每走到一步，判断这一步不能再走重复的数字


// coding的第一个错误 ，vis必须不能拷贝，
// 第二个 vis[i-1]写成了vis[i]
// 没有sort
class Solution {
    vector<int> vis;
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size() == 0){
            return res;
        }
        sort(nums.begin(), nums.end());
        vector<int> path;
        vector<vector<int>> ret;
        vis.resize(nums.size());
        backtrack(nums, 0, path,  ret);
        return ret;
    }

    void  backtrack(vector<int>& nums, int depth, vector<int> path, vector<vector<int>>& res){
        // vector<vector<int>> res;
        if(depth == nums.size()){
            res.push_back(path);
            return;
        }

        for(int i = 0;i<nums.size();i++){
            
            if(vis[i] || (i > 0 && nums[i] == nums[i-1] && !vis[i-1])){
                continue;
            }

            path.push_back(nums[i]);
            vis[i] = 1;
            backtrack(nums, depth+1, path,  res);
            vis[i] = 0;
            path.pop_back();
        }
    }
};

int main(){
    vector<int> nums = {1,2,1};
    Solution sl;
    sl.permuteUnique(nums);
}