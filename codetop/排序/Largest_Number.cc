/*
 * @Date: 2021-12-04 16:49:40
 * @LastEditors: kafier
 * @LastEditTime: 2021-12-04 16:52:35
 */
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](const int &x, const int& y){
            long sx = 10, sy = 10;
            // 拿出2和10 sy = 100
            while(sx <= x){
                sx *= 10;
            }
            while(sy <= y){
                sy *= 10;
            }
            return sy*x + y > sx*y + x;
            // sy*x+y = 100 * 2 + 10 ;;; sx * y + x == 10*10 + 2
        });

        if(nums[0] == 0){
            return "0";
        }

        string ret;
        for(int &x:nums)
        {
            ret += to_string(x);
        }

        return ret;
    }
};