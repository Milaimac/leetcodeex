#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        nrow_ = grid.size();
        ncol_ = grid[0].size();
        int count = 0;
        for(int i = 0;i<nrow_;++i)
        {
            for(int j = 0;j<ncol_;++j)
            {
                if(grid[i][j] == '1')
                {
                    ++count;
                    dfs(grid, i, j);
                }
            }
        }
        return count;
    }

    void dfs(vector<vector<char>>& grid, int row, int col)
    {
        // 先将目前遍历到设置为0 
        grid[row][col] = '0';
        for(int i = 0;i<4;++i)
        {
            int newRow = row + directions[i][0];
            int newCol = col + directions[i][1];
            if(newRow >= 0 && newRow < nrow_ && newCol >= 0 && newCol < ncol_ && grid[newRow][newCol] == '1')
            {
                dfs(grid, newRow, newCol);
            }
        }
    }

private:
    int directions[4][2] = {{1,0}, {-1, 0}, {0, 1}, {0, -1}};
    int nrow_, ncol_;
};

// 计算出岛屿的数量

// 先遍历一遍岛屿， 如果遇到有1的数字， 使用dfs将与之连通的1全部设置为0 ，而后可以得到岛屿的数量