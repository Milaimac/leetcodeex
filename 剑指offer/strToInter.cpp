// 剑指 Offer 67. 把字符串转换成整数
#include <string>
#include <limits>
#include <iostream>
using namespace  std;


class Solution {
public:
    int strToInt(string str) {
        if(str.length() == 0){
            return  0;
        }

        int res = 0, bdry = INT32_MAX;
        int i = 0, sign = 1, length = str.length();

        bool flag = false;
        if(length == 0){
            return  0;
        }

        // 空格， 字母，数字，符号
        while(i < length)
        {
            if(str[i] == ' ' && flag == false){
                i++;
                continue;
            }
            else if(str[i] == '-' && flag == false){
                sign = -1;
                flag = true;
            }else if(str[i] == '+' && flag == false){
                sign = 1;
                flag = true;
            }
            else if(str[i] < '0' || str[i] > '9' ){
                break;
            }
            else if(res > bdry || res == bdry && str[i] > '7'){
                return sign = 1? INT32_MAX : INT32_MIN;
            }
            else{
                res = res * 10 + (str[i] - '0');
                flag  = true;
            }
            i += 1;
        }
        return sign * res;
    }
};

int main(){
    string str = " +0 123";

    Solution sl;
    int res = sl.strToInt(str);
    cout << res << endl;
}