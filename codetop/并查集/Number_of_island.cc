/*
 * @Date: 2021-11-26 20:52:50
 * @LastEditors: kafier
 * @LastEditTime: 2021-12-06 18:25:16
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


class UninFind{
public:
    UninFind(vector<vector<char>>& grid)
    {
        count = 0;
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0;i < m;++i){
            for(int j = 0;j < n;++j)
            {
                if(grid[i][j] == '1')
                {
                    parent.push_back(i * n +j);
                    ++count;
                }
                else{
                    parent.push_back(-1);
                }
                rank.push_back(0);
            }
        }
    }

    int find(int i)
    {
        if(parent[i] != i)
        {
            parent[i] = find(parent[i]);
        }
        return parent[i];
    }

    void unite(int x,int y){
        int rootX = find(x);
        int rootY = find(y);
        if(rootX != rootY)
        {
            if(rank[rootX] < rank[rootY])
            {
                swap(rootX, rootY);
            }
            parent[rootY] = rootX;
            if(rank[rootX] == rank[rootY]) rank[rootX] += 1;
            --count;
        }
    }

    int getCount() const{
        return count;
    }
private:
    vector<int> parent;
    vector<int> rank;
    int count;
};

class Solution1{
public:
    int numIslands(vector<vector<char>> & grid)
    {
        int nr = grid.size();
        if(!nr) 
            return 0;
        int nc 
    }

}