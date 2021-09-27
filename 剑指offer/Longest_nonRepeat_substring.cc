#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;
// 剑指 Offer 48. 最长不含重复字符的子字符串
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = -1, j = 0;
        int res = 0;
        unordered_map<char,int> chartoIdx;
        for(auto& ch:s){
            if(!chartoIdx.count(ch)){
                // ++j;
                chartoIdx[ch] = j;
            }
            else{
                i = max(chartoIdx[ch], i);
                chartoIdx[ch] = j;
            }

            res = max(res, j-i);
            ++j;
        }
        return res;
    }
};

// dp[i]  表示前i个字符中，没有重复字符的字符串长度？
// 如何判断是否重复 --- 双指针
int main(){
    
}