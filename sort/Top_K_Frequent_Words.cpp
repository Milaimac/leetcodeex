#include<unordered_map>
#include<vector>
#include<iostream>
#include<algorithm>
#include<tuple>
using namespace std;
//692. 前K个高频单词
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> cnt;
        for(auto& word:words){
            cnt[word]++;
        }
        
        vector<string> rec;
        // for(auto& [key, value]:cnt){    //这个用法是C++17的标准
        //     rec.emplace_back(key);
        // }
        for(auto& element:cnt){
            rec.emplace_back(element.first);
        }
        sort(rec.begin(), rec.end(), [&](const string& a, const string& b)->bool{
            return cnt[a]==cnt[b] ? a<b : cnt[a] >cnt[b];
        });
        rec.erase(rec.begin()+k, rec.end());
        return rec;
    }
};

int main(){
    Solution sl;
    // sl.topKFrequent()
}