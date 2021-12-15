/*
 * @Date: 2021-12-04 20:26:15
 * @LastEditors: kafier
 * @LastEditTime: 2021-12-04 23:15:31
 */
#include <stack>
#include <string>
using namespace std;
class Solution {
public:
    string decodeString(string s) {
        int n = s.length();
        string res = "";
        stack<int> nums;
        stack<string> strs;
        int num = 0;
        string ret;
        for(int i = 0;i < n;++i){
            if(isdigit(s[i])){
                num = num * 10 + s[i] - '0';
            }
            else if(isalpha(s[i])){
                res += s[i];
            }
            else if(s[i] == '[')  // 将'['之前的数字压入栈， 字母字符串压入strs栈内 因为还是存在不在[]内的字符串的(还有包括之前的）。必须要把这个考虑在内
            {
                nums.push(num);
                num = 0;
                strs.push(res);
                res = "";
            }
            else{
                int times = nums.top();
                nums.pop();
                for(int j = 0;j < times;++j){
                    strs.top() += res;
                }
                res = strs.top();
                strs.pop();
            }
        }
        return res;
    }
};