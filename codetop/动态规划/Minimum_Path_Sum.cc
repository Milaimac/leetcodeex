/*
 * @Date: 2021-12-02 10:04:13
 * @LastEditors: kafier
 * @LastEditTime: 2021-12-02 11:01:29
 */
#include <vector>
#include <limits.h>
using namespace std;

// 使用dfs、 需要消耗O(n^2)的事件复杂度。 同O(n^2) 的空间复杂度
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        dfs(grid, 0,0,0);
        return ans;
    }
    // 只能向右和向下移动
    void dfs(vector<vector<int>>& grid, int i, int j, int acc){
        int m = grid.size(), n = grid[0].size();
        if(i >= m || j >= n){
            return;
        }
        acc += grid[i][j];
        if(i == m-1 && j == n-1){
            ans = min(ans, acc);
            return;
        }

        dfs(grid, i+1, j, acc);
        dfs(grid, i, j+1,acc);
    }

    int ans = INT_MAX;
};

class Solution1 {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size() , n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        dp[0][0] = grid[0][0];
        for(int i = 0;i < m;++i){
            for(int j = 0;j < n;++j){
                if(i == 0 || j == 0){
                    continue;
                }
                dp[i][j] = min(i >= 1 ? dp[i-1][j] : INT_MAX, j >= 1 ? dp[i][j-1] : INT_MAX)  + grid[i][j];
            }
        }
        return dp[m-1][n-1];
    }
};


