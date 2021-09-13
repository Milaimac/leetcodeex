#include<iostream>
using namespace std;
// 剑指 Offer 44. 数字序列中某一位的数字
class Solution {
public:
    int findNthDigit(int n) {
        int init = 10;
        if(n / init  == 0){
            return n;
        }
        int digit = 1, start = 1, count = 9;
        while(n > count){
            n -= count;
            ++digit;
            start *= 10;
            count = (digit*start*9);
            // n -= count;
        }
        long num = start + (n-1)/digit;
        int pos = (n-1)%digit;          //n = 4, 3/ 2 = 1. n = 3, 2/2 = 0
        int res = 0;
        for(int j = digit-1-pos;j>=0;--j){
            // num /=10;
            res = num%10;
            num/=10;
        }
        return res;
    }
};

int main(){
    int n = 12;
    Solution sl;
    cout << sl.findNthDigit(n) << endl;
}