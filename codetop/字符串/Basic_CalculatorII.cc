/*
 * @Date: 2021-12-04 20:02:10
 * @LastEditors: kafier
 * @LastEditTime: 2021-12-04 20:12:29
 */
#include <vector>
#include <string>
// #include <algorithm>
#include <numeric>
using namespace std;
class Solution
{
public:
    /**
     * @description: 
     * 要是乘除的优先级。 可以通过栈， 保存这些（进行乘除运算后的）整数的值， 对于加减号的数字， 直接压入栈中。 
     * 对于乘除号后的数字， 可以直接和栈顶元素计算， 并且替换栈顶元素
     * @param {string} s
     * @return {*}
     */
    int calculate(string s)
    {
        vector<int> stk;
        char preSign = '+';
        int num = 0;
        int n = s.length();
        for (int i = 0; i < n; ++i)
        {
            if (isdigit(s[i]))
            {
                num = num * 10 + int(s[i] - '0');
            }
            if (!isdigit(s[i]) && s[i] != ' ' || i == n - 1)
            {
                switch (preSign)
                {
                case '+':
                    stk.push_back(num);
                    break;
                case '-':
                    stk.push_back(-num);
                    break;
                case '*':
                    stk.back() *= num;
                    break;
                default:
                    stk.back() /= num;
                }
                preSign = s[i];
                num = 0;
            }
        }
        return accumulate(stk.begin(), stk.end());
    }
};