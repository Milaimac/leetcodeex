#include <iostream>
using namespace std;
// 剑指 Offer 64. 求1+2+…+n
class Temp{
    Temp(){
        N++;
        sum+=N;
    }
    static void reset(){
        N=0;
        sum = 0;
    }

    static int getSum(){
        return sum;
    }
private:
    static unsigned int N;
    static unsigned int sum;
};