#include<iostream>
#include<vector>
#include<queue>

// 图像渲染，
// 有一幅以二维整数数组表示的图画，每一个整数表示该图画的像素值大小，数值在 0 到 65535 之间。

// 给你一个坐标 (sr, sc) 表示图像渲染开始的像素值（行 ，列）和一个新的颜色值 newColor，让你重新上色这幅图像。

// 为了完成上色工作，从初始坐标开始，记录初始坐标的上下左右四个方向上像素值与初始坐标相同的相连像素点，接着再记录这四个方向上符合条件的像素点与他们对应四个方向上像素值与初始坐标相同的相连像素点，……，重复该过程。将所有有记录的像素点的颜色值改为新的颜色值。

// 最后返回经过上色渲染后的图像。

// 为什么要使用队列
// 用这个队列来存储原先的位置， 以及从这个位置fill的位置
using namespace std;

class Solution {
public:
    const int dx[4] = {1, 0, 0, -1};
    const int dy[4] = {0, 1, -1, 0};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int currColor = image[sr][sc]; 
        if(currColor == newColor){
            return image;
        }

        int n = image.size(), m = image[0].size();

        queue<pair<int,int>> que;
        que.emplace(sr, sc);
        int temp = image[sr][sc];
        image[sr][sc] = newColor;
        while (!que.empty())
        {   auto [row, col]= que.front();

            que.pop();
            // floodFill(image, row)
            for(int i = 0;i<4;++i){
                if(row+dx[i] < 0 || row+dx[i] >= n || col+dy[i] <0 || col+dy[i] >= m || temp != image[row+dx[i]][col+dy[i]]){
                    continue;
                }
                image[row+dx[i]][col+dy[i]] = newColor;
                que.emplace(row+dx[i], col+dy[i]);
            }
        }
        return image;
        
    }
};

// 记录初始坐标上下左右

int main(){
    vector<vector<int>> image = { {1,1,1},{1,1,0},{1,0,1}};
    int sr = 1, sc = 1, newcolor = 2;
    Solution     sl;
    sl.floodFill(image, sr, sc, newcolor);
}