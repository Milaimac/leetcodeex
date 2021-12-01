/*
 * @Date: 2021-11-10 23:25:34
 * @LastEditors: kafier
 * @LastEditTime: 2021-11-10 23:53:42
 * @FilePath: /leetcodeex/codetop/动态规划/Longest_Increasing_Subsequence.cc
 */
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        vector<int> dp(len ,1 );
        for(int i = 0;i < len;++i){
            for(int j = 0;j < i;++j){
                if(nums[i] > nums[j]){
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
        }      
        return *max_element(dp.begin(), dp.end());
    }
    /**
     * @description: 
     * 使用贪心和二分查找
     * 考虑一个简单的贪心，如果我们要使上升子序列尽可能的长，则我们需要让序列上升得尽可能慢，因此我们希望每次在上升子序列最后加上的那个数尽可能的小。
     * 维护一个数组d[i]， 表示长度为i的最长上升子序列的末尾元素的最小值， 用len记录目前上升子序列的长度
     * @param {*}
     * @return {*}
     */    
    int lengthOfLIS1(vector<int>& nums){
        int len = nums.size();
        vector<int> tails(len);
        int res = 0;
        for(int& num:nums){
            int i = 0, j = res;
            while(i < j){
                int m = (i+j)/2;
                if(tails[m] < num)
                    i = m + 1;
                else 
                    j = m;
            }

            tails[i] = num;
            if(res == j)    res++;
        }
        return res;
    }
};

