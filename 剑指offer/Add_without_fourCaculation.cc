#include <iostream>
#include <stdio.h>
using namespace std;
// 剑指 Offer 62. 圆圈中最后剩下的数字
class Solution {
public:
    int add(int a, int b) {
        while(b!=0){
            int c = (a&b)<<1;
            a ^= b;
            b = c;
        }
        return a;
    }
};
// 位运算？
// 这里使用无符号数作为形参，是为了避免有符号数右移时补符号位
void recursion(int num)
{
    if (num > 0) {	// 判断是否大于0
        recursion(num >> 1);        // 递归调用，寻找不为0的最高位
        printf("%u", num & 1);      // 找到最高位后才开始输出
    }
    // recursion(num >> 1);        // 递归调用，寻找不为0的最高位
    // printf("%u", num & 1);      // 找到最高位后才开始输出
}

int main(){
    int a, b;
    Solution sl;
    cin >> a >> b;
    cout << sl.add(a, b) << endl;
}