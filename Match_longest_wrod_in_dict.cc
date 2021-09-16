#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
// 524. 通过删除字母匹配到字典里最长单词
// 解决两个问题
// - 如何判断字符串s的那些字符是可以删除的
// - 如何找到最长的长度和字典序最小的字符串

// 用双指针来解决第一个问题，第二个问题直接比较然后比较字典序即可
class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        string res  = "";
        for(auto &ele:dictionary){
            int i = 0, j = 0;
            while(i < s.size() && j < ele.size()){
                if(s[i] == ele[j]){
                    ++j;
                }
                ++i;
            }
            if(j == ele.size()){
                if(ele.size() > res.size() ||(ele.size() == res.size() && ele > res)){
                    res = ele;
                }
            }
            
        }
        return res;
    }
};


// 优化思路
// 提前给dict进行排序
class Solutionv1 {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        string res  = "";
        auto compare = [](const string a,const  string b){
            if(a.size() != b.size()){
                // return static_cast<bool> (a.size() - b.size());     // a > b return true else return false  事实证明，直接转型会引出数值上的错误
                return a.size() > b.size() ? true : false;
            
            }else{
                return a < b;
            }
        };
        sort(dictionary.begin(), dictionary.end(), compare);
        for(auto &ele:dictionary){
            int i = 0, j = 0;
            while(i < s.size() && j < ele.size()){
                if(s[i] == ele[j]){
                    ++j;
                }
                ++i;
            }
            if(j == ele.size()){
                return ele;
            }
            
        }
        return "";
    }
};

int main(){
    string str = "abpcplea";
    vector<string> dict = {"ale","apple","monkey","plea"};
    Solution sl;
    sl.findLongestWord(str, dict);

}