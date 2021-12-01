/*
 * @Date: 2021-11-29 15:39:33
 * @LastEditors: kafier
 * @LastEditTime: 2021-11-29 16:15:19
 */
#include <vector>
using namespace std;
class Solution {
private:
    static constexpr int directions[4][2] = {{0,1}, {1,0}, {0,-1}, {-1, 0}};
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0)
        {
            return  {};
        }

        int rows= matrix.size(), columns = matrix[0].size();
        vector<vector<bool>> visited (rows, vector<bool> (columns));
        int total = rows * columns;
        vector<int> order(total);

        int row = 0, col = 0;
        int directionIndex = 0;     //4个方向轮流转
        for(int i = 0;i<total;++i){
            order[i] = matrix[row][col];
            visited[row][col] = true;
            int nexRow = row + directions[directionIndex][0], nextcolumn = col + directions[directionIndex][1];
            if(nexRow < 0 || nexRow >= rows || nextcolumn < 0 || nextcolumn >= columns || visited[nexRow][nextcolumn])
            {
                directionIndex = (directionIndex + 1) % 4;
            }
            row += directions[directionIndex][0];
            col += directions[directionIndex][1];

        }
        return order;
    }
    /**
     * @description: 
     * 按层遍历， 
     * 1. 从左到右遍历上侧元素， (top, left) 到 (top, right)
     * 2. 从上到下遍历右侧元素, (top + 1, right) 到 (bottom ,right)
     * 3. 从右到左遍历下侧元素 (bottom,  right-1) 到 (bottom, left+1)
     * 4. 从下到上遍历左侧元素 (bottom-1, left) 到 (top+1, left)
     * @param {*}
     * @return {*}
     */    
    vector<int> spiralOrder1(vector<vector<int>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        if(m == 0 || n == 0)
        {
            return {};
        }
        int top = 0, left = 0, bottom = m-1, right = n-1;
        vector<int> order;
        while(left <= right && top <= bottom)
        {
            for(int col = left;col < right;++col)
            {
                order.emplace_back(matrix[top][col]);
            }
            for(int row = top;row < bottom;++row)
            {
                order.emplace_back(matrix[row][right]);
            }
            for(int col = right-1;col >= left;--col)
            {
                order.emplace_back(matrix[bottom][col]);
            }
            for(int row = bottom+1;row >= top;--row)
            {
                order.emplace_back(matrix[row][left]);
            }
            ++left;
            --right;
            ++top;
            --bottom;
        }
        return order;
    }

};

