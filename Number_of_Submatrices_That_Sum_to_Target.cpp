#include"head.h"
class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size(), ans = 0;
        for(int i=0;i<m;i++){
            for(int j=1;j<n;j++){
                matrix[i][j] += matrix[i][j-1];
            }
        }

        for(int k=0;k<m;k++){
            for(int j=k;j<m;j++){
                int sum = 0;
                unordered_map<int, int> mp = {{0,1}};
                for(int i=0;i<n;++i){
                    sum += (k == 0 ? matrix[i][j] : matrix[i][j] - matrix[i][k-1]);
                    if(mp.count(sum - target)) ans+= mp[sum - target];
                    ++mp[sum];
                }
            }
        }
        return ans;
    }
};