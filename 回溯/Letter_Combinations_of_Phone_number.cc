#include <vector>
#include <unordered_map>
#include <string>
using namespace std;
//#17 电话号码的字母组合
class Solution {
public:
    // the digits is stirng , so use char to string map 
    vector<string> letterCombinations(string digits) {
        vector<string> combinations;
        if(digits.empty()){
            return combinations;
        }
        unordered_map<char, string> PhoneMap {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        string combination = "";
        backtrack(combinations, PhoneMap, combination, digits, 0);
        return combinations;
    }
    // 用递归来避免第一个循环，从而实现在所谓“第二个循环”实现回溯
    // 这样就在给函数加个参数， index，代表的 是digits的index
    void backtrack(vector<string> &combinations, const unordered_map<char, string>& PhoneMap, string& combination, string& digits, int index){
        // how to backtrack
        if(combination.size() == digits.size()){
            combinations.push_back(combination);
            return;
        }
        char digit = digits[index];
        string letters = PhoneMap.at(digit);
        for(const char& letter:letters){
            combination.push_back(letter);
            backtrack(combinations, PhoneMap, combination, digits, index);
            combination.pop_back();
        }
    }
};