// 剑指 Offer 16. 数值的整数次方
#include<iostream>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        // x^n
        // 把n变为二进制，n = 1xb_1 + 2xb_2 + 4xb_3 + 8xb_4+ ....
        // 那么x^n = x^b_1 * x^2b_2 * x+4b_3 + ....
        // 又可以简化为 x^n = x^{2^0b_1} + x^{2^1b_2} + .... 
        // 当b_i = 0时， x^{2^{i-1}b_i} = 1 
        // 当b_i = 1时， x^{2^{i-1}b_i} = x^{2^{i-1}}

        // 分治
        // x^n = x^{n/2} * x^{n/2} = (x^{n/2})^2,令n/2为整数，则需要分为奇偶两种情况。

        if(x == 0){
            return 0;
        }

        long b = n;
        double res = 1.0;
        if(b < 0){
            x =1/x;
            b = -b;
        }
        while(b > 0){
            if((b&1) == 1 ){
                res *= x;
            } 
            x *= x;
            b >>= 1;
        }

        return res;
    }
};

// 时间复杂度 分析
// log2(n);