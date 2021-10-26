#include<map>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
static bool cmp(const pair<int, int> &p1, const pair<int, int> &p2){
    return p1.second < p2.second;
}

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int n = wall.size();
        map<int, int> split_count;
        for(int i = 0;i<n;i++){
            int split = 0;
            for(int j=0;j<wall[i].size();j++){
                split += wall[i][j];
                split_count[split]++;
            }
        }
        
    }
};