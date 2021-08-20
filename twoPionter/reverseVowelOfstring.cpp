#include <string>
#include <iostream>
using namespace  std;

class Solution {
public:
    string reverseVowels(string s) {
        int length = s.length();
        if(length == 0){
            return "";
        }

        string vowels = "aeiouAEIOU";
        auto isVowel = [vowels](char ch){
            return vowels.find(ch) != string::npos;     //stirng::npos是个特殊值，说明没有找到匹配
        };

        // auto a = "aa"s;

        int n = s.size();
        int i = 0, j = n-1;

        while(i < j){
            while(i < n && !isVowel(s[i])){
                ++i;
            }
            while(j > 0 && !isVowel(s[j])){
                --j;
            }

            if(i < j){
                swap(s[i], s[j]);
                ++i;
                --j;
            }
        }
        return s;
    }
};


int main(){
    string s = "abco";
    Solution sl;
    string res = sl.reverseVowels(s);
    cout << res << endl;   
}