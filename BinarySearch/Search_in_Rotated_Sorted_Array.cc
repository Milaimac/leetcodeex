/*
 * @Date: 2021-11-05 13:08:47
 * @LastEditors: kafier
 * @LastEditTime: 2021-11-06 22:13:56
 * @FilePath: /leetcodeex/BinarySearch/Search_in_Rotated_Sorted_Array.cc
 * 33. 搜索旋转排序数组
 */
#include <vector>

#include <iostream>

using namespace std;

// mid 左右两边， 必定有一边是有序的，
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int len = nums.size();
        int left = 0, right = len - 1;

        if (len == 0)
            return -1;
        if (len == 1)
            return nums[0] == target ? 0 : -1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (target == nums[mid])
            { // 直接判断
                return mid;
            }
            if (nums[0] <= nums[mid])
            {
                // it means the left intevals is sorted
                // if(target < nums[mid]){          // must ensure the target is in the left sorted intervals
                if (nums[0] <= target && target < nums[mid])
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
            else
            {
                if (nums[mid] < target && target <= nums[len - 1])
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }
            }
        }

        return -1;
    }
};

/**
 * @description: 
 * 问题： 为什么 right 的初始值不是num.size() 而是nums.size()-1， 因为需要拿出来用 nums[right] 需要拿出来比较
 * @param {*}
 * @return {*}
 */
// 换种二分的做法
class Solution1
{
public:
    int search(vector<int> &nums, int target)
    {
        int l = 0, r = nums.size() - 1, mid;
        while (l < r)
        { //稍微改一下二分的算法就行，有手就行的题目
            mid = (l + r) >> 1;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < nums[r])
            { // 在旋转数组的后半部分
                // 如果是target 在后半数组并且target在右边
                if (nums[mid] < target && nums[r] >= target)
                {
                    l = mid + 1;
                }
                else
                {
                    r = mid;
                }
            }
            else
            { // 在旋转数字的前半部分
                if (nums[mid] > target && nums[l] <= target)
                {
                    r = mid;
                }
                else
                {
                    l = mid + 1;
                }
            }
        }
        return nums[l] == target ? l : -1;
    }

};


