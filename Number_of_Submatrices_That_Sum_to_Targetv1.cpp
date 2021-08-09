#include"head.h"
class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size(), ans = 0;
        //前缀和预处理
        for(int i = 0; i < m; ++i)
            for(int j = 1; j < n; ++j)
                matrix[i][j] += matrix[i][j-1];
        
        for(int k = 0; k < n; ++k)
        {
            for(int j = k; j < n; ++j)
            {
                int sum = 0;
                //加入 {0,1} 以0，0为左上角的区间和等于target，属于边界情况
                unordered_map<int, int> mp = {{0,1}};
                for(int i = 0; i < m; ++i)
                {
                    //计算当前区间的区间和
                    sum += (k == 0? matrix[i][j] : matrix[i][j] - matrix[i][k-1]);
                    if(mp.count(sum - target)) ans += mp[sum - target];
                    ++mp[sum];
                }
            }
        }
        return ans;
    }
};

