/*
 * @Date: 2021-12-03 11:03:16
 * @LastEditors: kafier
 * @LastEditTime: 2021-12-03 11:06:54
 */
#include <vector>
using namespace std;
class Solution {
public:
    
    /**
     * @description:
     * 要知道从左上标点 到 右下标点的距离
     * 可以使用dp数组来存储
     * 
     * 或者使用组合数学 
     * 从左上角到右下角， 需要移动m+n-2次， 其中m-1次向下移动， n-1次向右移动。 因此路径的总数就等于在m+n-2次移动中选择m-1次向下移动的方案数， 即组合数
     * 
     * @param {int} m
     * @param {int} n
     * @return {*}
     */
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n));
        
        // 初始化首行和首列
        for(int i = 0;i < m;++i){
            dp[i][0] = 1;
        }

        for(int j = 0;j < n;++j){
            dp[0][j] = 1;
        }

        for(int i = 1;i < m;++i){
            for(int j = 1;j < n;++j){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};