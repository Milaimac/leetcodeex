// 剑指 Offer 29. 顺时针打印矩阵


#include<vector>
using namespace std;

// 方案一， 直接模拟
//1.创建方向数组 [1,0], [0,-1], [-1,0], [0,1]
//2.确认边界条件（在什么情况下，需要改变方向的条件）
// 2.1 数组越界
// 2.2 到达已访问的边界
class Solution {
private:
    static constexpr int directions[4][2] = {{0,1}, {1, 0}, {0, -1}, {-1, 0}};

public:

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() ==0){
            return {};
        }
        
        
        int rows  = matrix.size(), colums = matrix[0].size();
        int total = rows * colums;
        int col = 0, row = 0;

        int directionIndex = 0;
        vector<vector<bool>> visited(rows, vector<bool>(colums));
        vector<int> order(total);
        
        for(int i = 0;i<total;i++){
            order[i] = matrix[row][col];
            visited[row][col] = true;
            int nextrow = row+directions[directionIndex][0], nextcolum = col+directions[directionIndex][1];
            if(nextrow < 0 || nextrow >= rows || nextcolum < 0||nextcolum >= colums || visited[nextrow][nextcolum]){
                directionIndex = (directionIndex+1)%4;
            }
            row += directions[directionIndex][0];
            col += directions[directionIndex][1];
        }
        return order;
    }
};