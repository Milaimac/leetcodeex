// 77. 组合
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:

    void dfs(vector<vector<int>> &res, int n, int k, vector<int> path, int idx){
        if(path.size() == k){
            res.push_back(path);
            return ;
        }
        // if(idx > n){
        //     return ;
        // }
        if(path.size() + (n-idx+1) < k){
            return;
        }

        // pass 
        dfs(res, n, k, path, idx+1);
        
        if(path.size() < k && idx <= n){
            path.push_back(idx);
            dfs(res, n, k, path, idx+1);
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(res, n, k, path, 1);
        return res;
    }
};

int main(){
    Solution sl;
    sl.combine(20, 16);
    
}