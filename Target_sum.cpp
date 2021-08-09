#include"head.h"
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
    }
};


// 背包问题
/*
将数组的元素和记为sum， 添加-号元素之和为neg， 则其余添加+号的元素之和为sum-neg,

（sum-neg)-neg = sum -2*neg  = target

(sum - target)/2 = neg;

由于数组nums中的元素都是非负整数，neg也是如此，如果sum-target % 2 != 0,那么方案数为0.

背包定义dp数组

dp[i][j]为数组前i个元素中选取元素，使得这些元素之和等于j的方案数。  假设数组长度为n，那么最终答案为dp[n][neg]
*/
