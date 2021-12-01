/*
 * @Date: 2021-11-09 10:51:45
 * @LastEditors: kafier
 * @LastEditTime: 2021-11-09 11:41:58
 * @FilePath: /leetcodeex/codetop/哈希表/Maximum_Length_of_Repeated_Subarray.cc
 */
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1));
        int ans = 0;
        for(int i = m-1;i >= 0;--i){
            for(int j = n-1;j >= 0;--j){
                dp[i][j] = nums1[i] == nums2[j] ? dp[i+1][j+1]+1:0;
                ans = max(ans, dp[i][j]);
            }
        }      
        return ans;
    }
};
/**
 * @description: 
 * 滑动窗口法解决
 *  1. 两个数组交错找到公共子数组。 
 *  2. 利用索引将从addA开始
 * @param {*}
 * @return {*}
 */
class Solution1 {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int ret = 0;
        for(int i = 0;i < m; ++i){
            int len = min(m-i, n);
            ret = max(ret, maxLength(nums1, nums2, i, 0, len));                                     
        }

        for(int i = 0;i < n; ++i){
            int len = min(m, n-i);
            ret = max(ret, maxLength(nums1, nums2,0, i, len));
        }
        return ret;
    }


    int maxLength(vector<int>& nums1, vector<int>& nums2, int startInd1, int startInd2, int len){
        int length = 0;
        int maxlength = 0;
        for(int k=0;k < len;++k){
            if(nums1[startInd1 + k] == nums2[startInd2 + k]){
                ++length;
                maxlength = max(maxlength, length);
            }
            else{
                length = 0;
            }
        }
        return maxlength;
    }
};