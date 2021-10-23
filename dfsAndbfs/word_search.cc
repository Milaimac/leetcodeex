#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:
    int directions[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    int m_, n_;
    bool exist(vector<vector<char>>& board, string word) {
        m_ = board.size(), n_ = board[0].size();
        for(int i = 0;i < m_;++i)
        {
            for(int j = 0;j < n_;++j)
            {
                if(dfs(board, word, i,j,0))
                {
                    return true;
                }
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& board, string word, int row, int col, int index)
    {
        char ch = board[row][col];
        if(ch != word[index]) // 这里直接比较了
        {
            return false;
        }
        else if(index == word.size()-1)
        {
            return true;
        }

        board[row][col] = '#';
        // 四个方向直接遍历
        bool result = false;
        for(int i = 0;i < 4;++i)
        {
            int newRow = directions[i][0] + row;
            int newCol = directions[i][1] + col;
            // 不能重用之前的， 不能越界
            if(newRow >= 0 && newRow < m_ && newCol >= 0 && newCol < n_)// 为什么要把board[newRow][newCol]写到if里面， 是因为避免数组溢出
            {
                if(board[newRow][newCol] != '#')
                {
                    bool flag = dfs(board, word, newRow, newCol, index+1); // 这样不行， 如果遍历数组中最后一个是false， 那它就是false
                    if(flag){
                        result = true;
                        break;
                    }
                }
                
            }   
        }
    
        board[row][col] = ch;
        // return true;
        return result;
    }
};

int main()
{
    vector<vector<char>> str = {{'A','B','C', 'E'},{'S','F','C','S'},{'A','D','E','E'}};
    string word = "ABCCED";
    Solution sl;
    cout << sl.exist(str, word) << endl;
}