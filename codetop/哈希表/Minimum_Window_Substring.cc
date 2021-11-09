/*
 * @Date: 2021-11-08 11:33:05
 * @LastEditors: kafier
 * @LastEditTime: 2021-11-09 09:12:09
 * @FilePath: /leetcodeex/codetop/哈希表/Minimum_Window_Substring.cc
 */
#include <string>
#include <unordered_map>
using  namespace std;
/**
 * @description: 
 * 用一个哈希表存下t字符串中对应的字符的坐标 ， 通过比较最大坐标和最小坐标的差 得到 长度。
 * 由于t中有重复字符 所以哈希表应该还是要存储对应的频次， 但是要实现判断满足t字符串的时候，进行判断那个最小 
 * 使用distance 当有满足t字符串中的字符的时候进行++ 
 * @param {*}
 * @return {*}
 */
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> tfreq;
        unordered_map<char, int> sfreq;
        int slen = s.length(), tlen = t.length();
        if(slen == 0 || tlen == 0 || slen < tlen){
            return "";
        }
        for(const auto& ch: t){
            ++tfreq[ch];
        }

        int left = 0, right = 0;
        int distance = 0;
        int minlen = slen + 1;
        int begin;
        while(right < slen){// 最重要的错误
            const auto& chRight = s[right];     // charRight  是现在遍历的最右边
            if(tfreq[chRight] == 0){
                ++right;
                continue;
            }

            if(sfreq[chRight] < tfreq[chRight]){
                //sfreq表示现在遍历到的次数，这种情况只有chRight是t中的时候才会发生
                ++distance;
            }
            sfreq[chRight]++;
            right++;
            while(distance == tlen){
                // 说明这个子串是符合条件的
                if(minlen > right - left){
                    minlen = right - left;
                    begin = left;       //要将这个数保持
                }

                if(tfreq[s[left]] == 0){
                    ++left;
                    continue;
                }

                // 这个必须设置表示 sfreq和tfreq相同
                if(sfreq[left] == tfreq[left]){
                    distance--;
                }
                sfreq[left]--;
                ++left;
            }
        
        }
        return s.substr(begin, minlen);
    }


};