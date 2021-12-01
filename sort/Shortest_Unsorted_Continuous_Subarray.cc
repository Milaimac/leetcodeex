/*
 * @Date: 2021-11-06 11:07:28
 * @LastEditors: kafier
 * @LastEditTime: 2021-11-06 13:00:31
 * @FilePath: /leetcodeex/sort/Shortest_Unsorted_Continuous_Subarray.cc
 * 581. 最短无序连续子数组
 */
#include <vector>
#include <algorithm>
using namespace std;
/**
 * @description:
 *  找到一个区间包含了所有乱序的元素 , 设这个区间为 [i, j] 其中在[0, i-1] 区间内的元素小于子数组中的元素，  
 * @param {*}
 * @return {*}
 */
class Solution {
public:
    /**
     * @description:  一个简单的方法， 就是把原数组进行排序， 而后对两个数组进行比较， 如果出现了不同的数， 那么就将其记录起来， 得到区间方位， 也就是result。
     * @param {*}
     * @return {*}
     */
    int findUnsortedSubarray(vector<int>& nums) {
        if(is_sorted(nums.begin(), nums.end())){
            return 0;
        }
        vector<int> sorted_nums(nums);
        sort(sorted_nums.begin(), sorted_nums.end());
        int sizxe = sorted_nums.size();
        int left = 0;
        while(nums[left] == sorted_nums[left]){
            ++left;
        }
        int right = sizxe-1;
        while(nums[right] == sorted_nums[right]){
            --right;
        }

        return right-left+1;
    }
    /**
     * @description: 要做到一次遍历（没有将原数组存储起来） 存储两个值， 较大的最小值， 较小的最大值
     * @param {*}
     * @return {*}
     */    
    int findUnsortedSubarray1(vector<int>& nums) {
        int size = nums.size();
 
    }
};