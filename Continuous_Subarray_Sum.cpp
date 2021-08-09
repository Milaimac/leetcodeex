// 连续的子数组和

// 要求的是子数组总和为k的倍数
#include"head.h"
class Solution{
public: 
    bool checkSubarraySum(vector<int>& nums, int k){
        int m = nums.size();
        if(m < 2){
            return false; // 连子数组的最小个数都凑不起
        }

        unordered_map<int, int> mp;
        mp[0] = -1;
        int remainder = 0; //余数
        //通过余数累加的方式，去实现前缀和的思想

        for(int i=0;i<m;i++){
            remainder = (remainder + nums[i])%k;
            if(mp.count(remainder)){
                int preIndex = mp[remainder];
                if(i - remainder >= 2){
                    return true;
                }
            }else {
                mp[remainder] = i;
            }
        }
        return false;
    }
};