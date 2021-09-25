#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> set;
        int maxlen = 0;
        for(auto& ch:s){
            if(!set.count(ch)){
                // set.insert(ch);
                set[ch] += 1;
            }
            else{
                maxlen = max(static_cast<int>( set.size()), maxlen);
                set.clear();
            }
            
        }
        return maxlen;
    }
};

// dp[i]  表示前i个字符中，没有重复字符的字符串长度？
// 如何判断是否重复 --- 双指针
int main(){
    
}