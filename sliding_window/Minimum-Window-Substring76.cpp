#include<string>
#include<iostream>
#include<unordered_map>
#include<memory>
using namespace std;
class Solution {
public:
    unordered_map<char, int> sfreq, tfreq;
    
    string minWindow(string s, string t) {
        int slen = s.length();
        int tlen = t.length();
        if(slen == 0 || tlen == 0 || slen < tlen){
            return "";
        }

        for(auto &ch:t){
            tfreq[ch] ++;
        }

        int distance =  0;
        int minlen = slen+1;
        int begin = 0;


        int left = 0;
        int right = 0;

        while(right < slen){
            char charRight = s[right];
            if(tfreq[charRight] == 0){
                right++;
                continue;
            }

            if(sfreq[charRight] < tfreq[charRight]){
                distance++;
            }
            sfreq[charRight]++;
            right++;


            while(distance == tlen){
                if(right - left < minlen){
                    minlen = right-left;
                    begin = left;
                }

                char charLeft = s[left];
                if(tfreq[charLeft] == 0){
                    left++;
                    continue;
                }

                if(sfreq[charLeft] == tfreq[charLeft]){
                    distance--; 
                }
                sfreq[charLeft] --;
                left++;

            }
        }

        if(minlen == slen + 1){
            return "";
        }
        string res = s.substr(begin, minlen);
        return res; 
    }

};




// 第一 如何确定最小覆盖子串

// 使用滑动窗口法来决定最小子串的左边界和右边界

// 第二 如何确认子串是否和给出的字符串T相符合 ——使用哈希表
// 使用哈希表存储字符串t的频次，再和子串的相比较。

int main(){
    Solution sl;

    string s = "ADOBECODEBANC";
    string t = "ABC";

    
    string res = sl.minWindow(s,  t);
    cout << res << endl;

}