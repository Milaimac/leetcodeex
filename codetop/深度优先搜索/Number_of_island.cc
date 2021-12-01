/*
 * @Date: 2021-11-26 20:52:50
 * @LastEditors: kafier
 * @LastEditTime: 2021-11-26 23:14:01
 */
#include <vector>
using namespace std;
class Solution {
public:
    // 思路很简单， 对于已经遍历的节点设置为0，但是碰到的时候就可以给结果加1
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if(!m){
            return 0;
        }
        int acc = 0;
        for(int i = 0;i < m;++i){
            for(int j = 0;j < n;++j){
                if(grid[i][j] == '1'){
                    ++acc;
                    dfs(grid, i, j);
                }
            }
        }        
        return acc;
    }

    void dfs(vector<vector<char>>& grid, int row, int column){
        int m = grid.size();
        int n = grid[0].size();
        if(grid[row][column] == '0'){
            return;
        }
        grid[row][column] = '0';
        for(int i = 0;i < 4;++i){
            int newrow = row + direction[i][0];
            int newcol = column + direction[i][1];
            if(newrow >=0 && newrow < m && newcol >= 0 && newcol < n){
                dfs(grid, newrow, newcol);
            }
        }
    }

    int direction[4][4] = {{0,1}, {0,-1}, {1,0}, {-1, 0}};

};