/*
 * @Date: 2021-11-11 13:56:20
 * @LastEditors: kafier
 * @LastEditTime: 2021-11-11 22:49:12
 * @FilePath: /leetcodeex/codetop/动态规划/Trapping_Rain_Water.cc
 */
#include <vector>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        int len = height.size();
        vector<int> leftMax(len);
        vector<int> rightMax(len);
        leftMax[0] = height[0];
        for(int i = 1;i < len;++i){
            leftMax[i] = max(leftMax[i-1], height[i]);
        }

        rightMax[len-1] = height[len-1];
        for(int i = len-2;i >= 0;--i){
            rightMax[i] = max(rightMax[i+1], height[i]);
        }

        int ans = 0;
        for(int i = 0;i < len;++i){
            ans += min(leftMax[i], rightMax[i]) - height[i];
        }

        return ans;
    }
    /**
     * @description: 
     * 接下来采用单调栈做法， 
     * @param {*}
     * @return {*}
     */
    int trap1(vector<int>& height){
        int len = height.size();

    }
};