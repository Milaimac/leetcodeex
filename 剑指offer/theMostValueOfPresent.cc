#include <iostream>
#include <vector>
using namespace std;
//剑指 Offer 47. 礼物的最大价值

// 这个dfs没有问题，时间复杂度高。
// 来计算一下时间复杂度
// 首先计算一条路劲就需要 O(n*m).那么计算全部路径就需要O(n*m*(m+n))
class Solution {
public:
    int dir[2][2] = {{1,0}, {0,1}};
    int maxValue(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        // used = vector<vector<int>> (m, vector<int>(n, 0));
        dfs(grid,0,0,0);
        return res;
        
    }
    // 走过的路径需要做标记
    void dfs(vector<vector<int>> &grid, int x, int y, int sum){
        // int sum;
        sum += grid[x][y];
        
        if(x == m-1 && y == n-1){
            res = max(res, sum);
            return;
        }

        for(int i = 0;i < 2;i++){
            int newx = x + dir[i][0];
            int newY = y + dir[i][1];
            if(newx >= 0 && newx < m && newY >= 0 && newY < n){
                dfs(grid, newx, newY, sum);
                // continue;
            }
        }
    }
    
    int res = 0; 
    int m,n;
    // vector<vector<int>> used;

};


// dfs问题 

class SolutionV1 {
public:
    // 前面已经知道使用dfs做，需要 消耗O(mn(m+n))的时间复杂度
    // 那么使用dp做法来简化复杂度

    // 由于这波只能走到右边和下边
    // 那么dp转移公式 
    // dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + grid[i][j]
    int maxValue(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        // vector<vector<int>> dp(m, vector<int>(n, 0));
        // dp[0][0] = grid[0][0];
        for(int i =0;i <m;++i){
            for(int j = 0;j < n;++j){
                if(i == 0 && j == 0){
                    continue;
                }
                if(i == 0){
                    // 这波懒得创建一个新数组，直接在原来的数组操作
                    grid[i][j] = grid[i][j-1]; 
                } 
                else if(j == 0){
                    grid[i][j] = grid[i-1][j];
                }
                else{
                    grid[i][j] = max(grid[i-1][j], grid[i][j-1]) + grid[i][j];
                }
            }
        }
        return grid[m-1][n-1];
    }   
};

int main(){
    vector<vector<int>> input = {   
        {5,0,1,1,2,1,0,1,3,6,3,0,7,3,3,3,1},
        {1,4,1,8,5,5,5,6,8,7,0,4,3,9,9,6,0},
        {2,8,3,3,1,6,1,4,9,0,9,2,3,3,3,8,4},
        {3,5,1,9,3,0,8,3,4,3,4,6,9,6,8,9,9},
        {3,0,7,4,6,6,4,6,8,8,9,3,8,3,9,3,4},
        {8,8,6,8,3,3,1,7,9,3,3,9,2,4,3,5,1},
        {7,1,0,4,7,8,4,6,4,2,1,3,7,8,3,5,4},
        {3,0,9,6,7,8,9,2,0,4,6,3,9,7,2,0,7},
        {8,0,8,2,6,4,4,0,9,3,8,4,0,4,7,0,4},
        {3,7,4,5,9,4,9,7,9,8,7,4,0,4,2,0,4},
        {5,9,0,1,9,1,5,9,5,5,3,4,6,9,8,5,6},
        {5,7,2,4,4,4,2,1,8,4,8,0,5,4,7,4,7},
        {9,5,8,6,4,4,3,9,8,1,1,8,7,7,3,6,9},
        {7,2,3,1,6,3,6,6,6,3,2,3,9,9,4,4,8}
    };

    SolutionV1 sl;
    cout << sl.maxValue(input) << endl;
}
