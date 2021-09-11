#include<iostream>
#include<vector>
#include<queue>

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