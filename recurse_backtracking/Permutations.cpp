// 46. 全排列
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        int len = nums.size();
        if(len == 0){
            return  res;
        }
        vector<bool> used = {false};
        vector<int> path;
        dfs(nums, 0, len, used, path, res);
        return res;



    }


private:        
    void dfs(vector<int>& nums, int depth, int len, vector<bool> used, vector<int> &path, vector<vector<int>> &res){
        if(depth == len){
            res.push_back(path);
            return;
        }
        
        for(int i = 0;i < len;++i){
            if(!used[i]){
                path.push_back(nums[i]);
                used[i]  = true;
                dfs(nums, depth+1, len, used, path, res);

                used[i] = false;
                path.pop_back();

            }
        }
    }
    
};

int main(){
    Solution sl;
    vector<int> input = {1,2,3};
    auto res = sl.permute(input);
    int i;
}
