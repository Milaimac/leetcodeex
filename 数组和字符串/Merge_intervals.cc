#include <vector>
#include <algorithm>
using namespace std;
// 合并区间
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());
        for(auto &ele:intervals)
        {
            if(res.empty() || res.back()[1] < ele[0])
            {
                // the left > prex. rigth, it will not repeat in intervals  
                res.push_back(ele);
            }
            else{
                res.back()[1] = max(res.back()[1], ele[1]);
            }
        }
        return res;
    }
};