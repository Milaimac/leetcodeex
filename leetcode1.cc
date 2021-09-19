#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
 //第一题惨败，为什么哈希表不行 

// class Solution {
// public:
//     int minimumSwitchingTimes(vector<vector<int>>& source, vector<vector<int>>& target) {
//         vector<int> src,tar;
//         int ans = 0;
//         for(int i = 0;i<source.size();++i){
//             for(int j = 0;j<source[0].size();++j){
//                 src.push_back(source[i][j]);
//             }
//         }
        
//         for(int i = 0;i<target.size();++i){
//             for(int j = 0;j<target[0].size();++j){
//                 tar.push_back(target[i][j]);
//             }
//         }
//         sort(src.begin(), src.end());
//         sort(tar.begin(), tar.end());
//         for(int i = 0;i<src.size();++i){
//             if(src[i] != tar[i]){
//                 ++ans;
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int minimumSwitchingTimes(vector<vector<int>>& source, vector<vector<int>>& target) {
        unordered_map<int,int> set;
        int ans =0, tarnum = 0, srcnum = 0;
        for(int i = 0;i<source.size();++i){
            for(int j =0;j<source[0].size();++j){
                set[source[i][j]] += 1;
            }
        }
        // 如果target由src没有的，那么set[target[i][j]] < 0
        for(int i = 0;i<target.size();++i){
            for(int j =0;j<target[0].size();++j){
                set[target[i][j]] -= 1;
            }
        }
        
        for(auto[x, y] : set){
            ans += abs(y);
        }
        
        
        // for(auto ele:set){
        //     if(ele.second<0){
        //         tarnum++;
        //     }
        //     else{
        //         srcnum++;
        //     }
        // } 原来一个 数里面它可以由多个负数，我就是没有考虑这个啊，所以艹
        
        // return (tarnum+srcnum)/2;
        return ans/2;
        
    }
};