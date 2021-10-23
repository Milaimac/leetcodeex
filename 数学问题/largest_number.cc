#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

//最高位哪个越大，哪个越要排到前面。
// 将一个数组中的数排列成一个最大的数。
class Solution{
public:
    string largestNumber(vector<int> &nums){
        //将所有数变成同一个数量级，
        sort(nums.begin(), nums.end(), [](const int &x, const int &y){
            long sx =10, sy=10;
            while(sx < x){
                sx*=10;
            }
            while(sy < y){
                sy*=10;
            }
            return sy*x+y > sx*y+x; 
        });
        if(nums[0] == 0){
            return "0"; 
        }
        string res;
        for(int &x:nums){
            res += to_string(x);
        }
        return res;
    }
};