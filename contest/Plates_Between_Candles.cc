#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <map>
using namespace std;
class Solution {
public:
    // 对每个子字符串进行查找是不可以地
    // 将蜡烛地编号记录下来
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int len = s.size();
        // vector<int> theind;
        map<int,int> theind;
        for(int i = 0;i < len;++i){
            if(s[i] == '|'){
                theind[i] = i;
            }
        }
        int size = queries.size();
        vector<int> res(size);
        for(int i = 0;i < size; ++i){
            // 最后还是要查找到蜡烛的位置
            for(auto ele = theind.begin(); ele != theind.end();++ele){
                // unordered_map<int,int>::iterator it1;
                int left = 0, right = 0;
                int onlyone1 = 0, onlyone2 = 0;
                if(queries[i][0] <= ele->first && !onlyone1){ // 有维妮塔
                    left = ele->first;
                    onlyone1++;
                }
                // ele.first = 2, 那么left = 2, right = 2， 这种查找方法有问题
                if(queries[i][1] >= ele->first && !onlyone2){
                    right = ele->first;\
                    onlyone2++;
                }
                res[i] = right-left;
            }
        }
        return res;
    }
};

class Solution1{
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        // 同样， 先是将string s中蜡烛的位置存起来， 
        // 在 查询 queries 的时候找到 querites[0] < |left < |right < queries[1]
        vector<int> candles;
        vector<int> ret;
        int candleLen = s.size();
        for(int i = 0;i < candleLen; ++i){
            if(s[i] == '|'){
                candles.push_back(i);
            }
        }
        
        for(auto& querie: queries){
            auto left = lower_bound(candles.begin(), candles.end(), querie[0])-candles.begin();
            auto right = upper_bound(candles.begin(), candles.end(), querie[1]) - candles.begin();  
            --right;
            if(right <= 1){
                ret.push_back(0);
                continue;                
            }

            ret.push_back(candles[right] - candles[left] - (right-left+1)+ 1);        //两个距离的差  还要在减去蜡烛的数量
                
        }
        return ret;
    }
};

int main(){

    string s =  "**|**|***|";
    vector<vector<int>> queries = {{2,5},{5,9}};
    Solution sl;
    sl.platesBetweenCandles(s, queries);

}