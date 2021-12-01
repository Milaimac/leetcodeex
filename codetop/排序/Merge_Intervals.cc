/*
 * @Date: 2021-11-30 12:13:13
 * @LastEditors: kafier
 * @LastEditTime: 2021-11-30 14:44:47
 */
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() == 0){
            return {};
        }
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;
        for(int i = 0;i < intervals.size();++i)
        {
            int L = intervals[i][0],R = intervals[i][1];
            if(!merged.size() || merged.back()[1] < L){
                merged.push_back({L, R});
            }
            else{
                merged.back()[1] = max(merged.back()[1] , R);
            }
        }
        return merged;
    }
};