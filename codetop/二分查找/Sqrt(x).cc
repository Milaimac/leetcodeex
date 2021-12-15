/*
 * @Date: 2021-11-26 18:12:03
 * @LastEditors: kafier
 * @LastEditTime: 2021-12-06 12:13:11
 */
#include <math.h>
#include <iostream>
using namespace std;
class Solution {
public:
    /**
     * @description: 
     * 这道题有多种解法， 二分算是比较low 的解法
     * 思路，就是在一个[1 .. n]中的数字中匹配这个nums[mid] * nums[mid] = x;
     * 不仅如此， 还需要注意一个问题， 就是结果是小数的情况， 只需要将小数部分去掉， 那么不可以直接设置mid * mid = x，而后直接return； 
     * 而是要遍历到最后的情况。 
     * 
     * 
     * 这种情况， 我们可以设置一下两种二分的不同写法
     * 我们发现right 的设置不是关键因素， 因为基本上从1开始， x的开根号不可能比x还要小， 也就是说x本身就超出了这个范围(但是除了 x = 0 或者 x= 1)这种情况
     * @param {int} x
     * @return {*}
     */
    int mySqrt(int x) {
        int left = 0, right = x;
        int ans = -1;
        if(x == 1 || x == 0){
            return x;
        }
        while(left < right)
        {
            int mid = left + (right-left)/2;
            if((long long) mid * mid  <= x){
                ans = mid;
                left = mid + 1; //如果是浮点数， 可就不敢轻易地使用+1了
            }
            else{
                right = mid;
            }
        }
        return ans;
    }

    // 我们用C表示平方根的那个整数， C的平方根就是函数y = f(x) = x^2 + C 的零点
    // 牛顿迭代法 的本质是借助泰勒技术， 从初始值开始快速向零点逼近。 任取一个x0作为初始值。 在每次的跌打中， 我们找到图像上的点。 过该点作一条斜率为该点导数 f'(xi)的直线。 
    // 直线的方程 为 y = 2 xi( x - xi) + x^2 -C -->>> y - (yi+c) = 2xi(x - xi)
    // 其中y = 0, yi = xi^2 --- ->>>> -(xi^2+ C)/2xi + xi = x --->> xi/2 + C/2xi = x 
    // 该方法是二次收敛的， 相较于二分查找更快
    int mysqrt1(int x){
        if (x == 0){
            return 0;
        }
        double C = x, x0 = x;
        while(true){
            double xi = 0.5 * (x0 + C / x0);
            if(fabs(x0 - xi) < 1e-7){
                break;
            }
            x0 = xi;
        }
        return int(x0);
    }
};

// 如果要求精确到几位数

float Sqrt(float x)
{
    const float e = 0.0001;
    float low = 0, high = x, mid = (low + high) / 2;
    while(mid * mid - x > e || mid * mid - x < -e){
        if(mid * mid - x > e)
        {
            high = mid;
        }
        else if(mid * mid - x < -e){
            low = mid;
        }
        mid = (low+high) / 2;
    }
    return mid;
}

int main()
{
    float x = 4.0;
    cout << Sqrt(x) << endl;
}