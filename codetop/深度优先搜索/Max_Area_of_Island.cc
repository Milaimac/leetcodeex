/*
 * @Date: 2021-12-04 17:22:35
 * @LastEditors: kafier
 * @LastEditTime: 2021-12-04 17:28:20
 */
#include <vector>
using namespace std;
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m_ = grid.size();
        n_ = grid[0].size();
        for(int i =0;i < m_;++i){
            for(int j = 0;j < n_;++j){
                if(grid[i][j] == 1){
                    int cnt = 0;
                    dfs(grid, i, j, cnt);
                }
            }
        }
    }

    void dfs(vector<vector<int>>& grid, int row, int col, int& cnt){
        ++cnt;
        grid[row][col] = 0;
        for(int i =0;i < 4;++i){
            int newrow = row + directions[i][0];
            int newcol = col + directions[i][1];
            if(newrow >= 0 && newrow < m_ && newcol >= 0 && newcol < n_ && grid[newrow][newcol] == 1){
                dfs(grid, newrow, newcol, cnt);
            }
        }
        ret = max(ret, cnt);
    }

    int ret = 0;
    int m_, n_;
    int directions[4][2] = {{1, 0}, {-1, 0}, {0,1}, {0,-1}};
};