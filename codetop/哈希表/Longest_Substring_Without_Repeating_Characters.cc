/*
 * @Date: 2021-11-07 17:35:35
 * @LastEditors: kafier
 * @LastEditTime: 2021-11-07 20:06:24
 * @FilePath: /leetcodeex/codetop/哈希表/Longest_Substring_Without_Repeating_Characters.cc
 * 3. 无重复字符的最长子串
 */

#include <unordered_map>
#include <string>
using  namespace std;
/**
 * @description: 
 *  1. 用哈希表来记录它的最近一次出现的位置
    2. 每次都要更新右边界
    3. 每次要更新滑动窗口长度
    4. 其中边界问题是什么？———— 如何设置其中的起始位置， 比如说 aaaaa这种情况， 那么一开始的left边界应该就是-1, right = 0
    5. left = max(left, charToIndex[ch]) 虽然收应该和该重复字符最近的一次比较， 但是也要确保两个重复字符之间有无重复的， 所以应该是二者之间的最大值
 * @param {*}
 * @return {*}
 */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charToindex;
        int left = -1, right = 0;
        int length = 0;
        for(const auto& ch:s){
            if(!charToindex.count(ch)){
                // 第一次遇见
                charToindex[ch] = right;
            }
            else{
                // left = charToindex[ch];         // 最近的一次坐标 和  
                charToindex[ch] = right;
            }

            length = max(length, right-left);
            ++right;
        } 
        return length;
    }
};

int main(){
    string s ="abba";
    Solution sl;
    sl.lengthOfLongestSubstring(s);
}