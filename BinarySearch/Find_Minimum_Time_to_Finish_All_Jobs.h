#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//k是工人数量，jobs是工作
// 用二分查找法，先将jobs累加起来除以k，然后去查找这个数的最小。----> 不行，正常来讲更多的是后面和前面相加得到目标值。

// 动态规划。 要求最小工作时间。 

//DFS 
        
// 1723. 完成所有工作的最短时间
class Solution{
public:
    int ans = 0x3f3f3f3f;
    int n,_k;
    vector<int> _jobs;
    int minimumTimeRequired(vector<int>& jobs, int k) {
        _jobs = jobs;
        n = jobs.size();
        _k = k;
        vector<int> sum(_k);
        dfs(0,0,sum,0);
        return ans;
    }
    
    void dfs(int u,int used, vector<int>& sum, int maxm){
        if(maxm >= ans){
            return;
        }
        if(u==n){
            ans = maxm;
            return;
        }
        if(used < _k){
            sum[used] = _jobs[u];
            dfs(u+1, used+1, sum, max(sum[used], maxm));
            sum[used] = 0;
        }
        for (int i = 0; i < used; i++) {
            sum[i] += _jobs[u];
            dfs(u + 1, used, sum, max(sum[i], maxm));
            sum[i] -= _jobs[u];
        }
    }
};

