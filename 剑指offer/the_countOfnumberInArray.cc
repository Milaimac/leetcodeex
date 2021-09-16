#include <vector>
#include <algorithm>
using namespace std;
// 剑指 Offer 56 - 数组中数字出现的次数 
class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        vector<int> res;
        sort(nums.begin(),  nums.end());
        for(int i = 0;i<nums.size()-1;++i){
            if(nums[i] == nums[i+1]){
                continue;
            }
            else if(i > 0 || nums[i] == nums[i-1]){
                continue;
            }
            else{
                res.push_back(nums[i]);
            }
        }
        return res;
    }
};
// 查找出只出现一次的数字
// 排序，然后判断？
// 但是要求时间复杂度为O(n),空间复杂度为O(1)
// 只不过没有想到，官方题解是使用异或来达成的

class Solutionv1 {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int n = 0;
        for(auto& num:nums){
            n ^= num;
        }
        int m = 1;
        while((n & m) == 0){
            m <<= 1;
        }
        int x = 0, y = 0;
        for(auto& num:nums){
            if(num & m){
                x ^= num;
            }else{
                y ^= num;
            }
        }
        return vector<int> {x, y};
    }
};