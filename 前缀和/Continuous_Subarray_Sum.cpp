// 523. 连续的子数组和
// 给你一个整数数组 nums 和一个整数 k ，编写一个函数来判断该数组是否含有同时满足下述条件的连续子数组：

//     子数组大小 至少为 2 ，且
//     子数组元素总和为 k 的倍数。

// 如果存在，返回 true ；否则，返回 false 。

// 如果存在一个整数 n ，令整数 x 符合 x = n * k ，则称 x 是 k 的一个倍数。0 始终视为 k 的一个倍数。

// 要求的是子数组总和为k的倍数
#include<vector>
#include<unordered_map>
using namespace std;
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