/*
 * @Date: 2021-11-13 13:26:50
 * @LastEditors: kafier
 * @LastEditTime: 2021-11-13 19:26:56
 * @FilePath: /leetcodeex/codetop/字符串/StringTointeger.cc
 */
#include <string>
#include <unordered_map>
#include <vector>
#include <limits.h>
using namespace std;

class Solution
{
public:
    /**
     * @description: 
     * 丢弃无用的前导空格
     * 检查下一个字符为正还是负号， 确认是正数还是负数， 默认为负数
     * 如果是输入结尾， 或者是非数字的字符， 则字符串的其余部分将被忽略
     * 可以把前导0 给忽略 "00023" -- > "23" 
     * 如果超过范围应该截断
     * 
     * 条件过多， 如果直接写代码会导致代码臃肿, 画出一个自动机， 每输入一个字符观察其中的状态变化
     * @param {string} s
     * @return {*}
     */
    int myAtoi(string s)
    {
        for(auto& c:s){
            get(c);
        }
        return sign * ans;
    }

    string state = "start";
    unordered_map<string, vector<string>> table = {
        {"start", {"start", "signed", "in_number", "end"}},
        {"signed:", {"end", "end", "in_number", "end"}},
        {"in_number", {"end", "end", "in_number", "end"}},
        {"end", {"end", "end", "end", "end"}}};
    // 通过这个得到对应哈希表存储的状态
    int get_col(char c)
    {
        if (isspace(c))
            return 0;
        if (c == '+' or c == '-')
            return 1;
        if(isdigit(c)){
            return 2;
        }
        return 3;
    }

    int sign = 1;
    long long ans = 0;
    void get(char c)
    {
        state = table[state][get_col(c)];
        if (state == "in_number")
        {
            ans = ans * 10 + c - '0';
            ans = sign == 1? min(ans, (long long) INT_MAX ): min(ans, (long long) INT_MIN);
        }
        else if (state == "signed")
        {
            sign = c == '+' ? 1 : -1;
        }

        // =对于end 状态直接不管
    }
};