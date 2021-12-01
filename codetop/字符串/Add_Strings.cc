/*
 * @Date: 2021-11-12 15:21:55
 * @LastEditors: kafier
 * @LastEditTime: 2021-11-13 13:26:24
 * @FilePath: /leetcodeex/codetop/字符串/Add_Strings.cc
 */
#include <string>
using namespace std;
class Solution {
public:
    // 只能用竖式加法
    string addStrings(string num1, string num2) {
        int n = num1.length(), m = num2.length();
        // int maxlen = max(n, m);
        // int minlen = min(n, m);
        int index1 = n-1, index2 = m-1;
        auto tosum = [](char ch){
            return ch - '0'; 
        };
        int carry = 0;

        string res = "";
        int i = 1;
        for(i = 1;i < (n < m ? n : m)+1;++i){
            int sum = tosum(num1[n-i]) + tosum(num2[m-i]) + carry;
            if(sum >= 10){
                carry = 1;
                sum %= 10;
            }
            else{
                carry = 0;
            }
            // res += to_string(sum);
            res = to_string(sum) + res;
        }

        for(;i < (n > m ? n:m) + 1;++i){
            if(n > m){
                int sum = tosum(num1[n-i] + carry);
                if(sum >= 10){
                    carry = 1;
                    sum %= 10;
                }
                else{
                    carry = 0;
                }
                // res  = to_string(tosum(num1[n-i]) + carry) + res;
                // carry = 0;
                res = to_string(sum) + res;
            }
            else{
                int sum = tosum(num2[m-i] + carry);
                if(sum >= 10){
                    carry = 1;
                    sum %= 10;
                }
                else{
                    carry = 0;
                }
                // res  = to_string(tosum(num1[n-i]) + carry) + res;
                // carry = 0;
                res = to_string(sum) + res;
            }
            // carry = 0;
        }
        if(carry != 0){
            res = to_string(1) + res;
        }
        return res;
    }
};

int main(){
    string num1 = "6994";
    string num2 = "36";

    Solution sl;
    sl.addStrings(num1, num2);
}