// 60. 排列序列

#include<vector>
#include<string>
using namespace std;
class Solution {
public:

    string getPermutation(int n, int k) {
        factorial.resize(n+1);
        calcualtefatroial(factorial);
        used.resize(n, false);
        this->k = k;
        this->n = n;
        dfs(0);
        return res;
    }

    void dfs(int idx){
        if(idx == n){
            return;
        }
        int cnt = factorial[n-1-idx];
        for(int i = 0;i<n;++i){
            if(used[i]){
                continue;
            }
            if(cnt < k){
                k -= cnt;
                continue;
            }
            res += to_string(idx);
            used[idx] = true;
            dfs(idx+1);
            return;

        }
    }

    void calcualtefatroial(vector<int> &factorial){
        factorial[0] = 1;
        for(int i = 1;i<factorial.size();++i){
            factorial[i] = factorial[i-1]*i;
        }
        return;
    }
private:
    int k;
    int n; 
    vector<int> factorial;
    string res;
    vector<bool> used;
};