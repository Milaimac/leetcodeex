/*
 * @Date: 2021-11-13 19:30:04
 * @LastEditors: kafier
 * @LastEditTime: 2021-11-14 11:31:27
 * @FilePath: /leetcodeex/codetop/字符串/Reverse_Words_in_a_String.cc
 */
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    /**
     * @description: 
     * @param {string} s
     * 要做到能够将多余的空格给去除
     * 
     * 对于字符串可变的语言
     * 1. 先是对整个字符串进行反转， 然后对每个单词进行反转
     * @return {*}
     */
    string reverseWords(string s) {
        reverse(s.begin(), s.end());

        int n = s.size();
        int idx = 0;
        for(int start = 0; start < n;++start){
            if(s[start] != ' '){
                if(idx != 0)    s[idx++] = ' ';//如果不为空， 那么填一个空白字符将idx移动到下一个单词的开头位置
                int end = start;
                while(end < n && s[end] != ' ')
                    s[idx++] = s[end++];
                reverse(s.begin() + idx - (end - start), s.begin() + idx);
                start = end;
            }
        }
        s.erase(s.begin() + idx, s.end());
        return s;
    }
};