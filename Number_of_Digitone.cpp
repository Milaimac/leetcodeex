#include <iostream>
#include <vector>

using namespace  std;


// 1234 --- high = 123  cur = 4, low = 0
// low = 4, cur = 3, high = 12 digit = 10
//
class Solution{
public:
    int countDigitOne(int n){
        int digit = 1,res = 0;
        int high = n / 10, cur = n % 10, low = 0;
        while(high != 0 || cur != 0){
            if(cur == 0){
                res += high*digit;
            }
            else if(cur == 1){
                res += high*digit + low + 1;
            }
            else{
                res += (high+1)*digit;
            }
            low += cur*digit;
            cur = high % 10;
            high /= 10;
            digit *= 10;
        }
        return res;
    }
};