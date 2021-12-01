/*
 * @Date: 2021-11-06 22:22:34
 * @LastEditors: kafier
 * @LastEditTime: 2021-11-07 17:30:28
 * @FilePath: /leetcodeex/BinarySearch/Find_Minimum_in_Rotated_Sorted_Array_II.cc
 */
#include <vector>
#include <iostream>
using namespace std;
/**
 * @description:  如何判断边界问题？？？？
 * 这里的想法利用high来判断， 如果说nums[mid] < nums[high], 那么说明mid在右半部分， 那么min不会在右边， 所以忽略掉(high = mid)
 *                          如果说nums[mid] >  numms[high], 那么说明mid在左半部分， 那么min不会在左边（而且mid是在反转的那部分， 所以直接left = mid + 1
 * 
 *      为什么是low < high， 然而这个是由于上面的条件直接导致的， 我们可以知道这是一个已经确定可以查找到的情况。 如果使用low <= high， 那么很有可能陷入死循环（后面推理一下发现不会）
 *      因为right--， 
 *     
 * @param {*}
 * @return {*}
 */
class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        while (low < high) {
            int pivot = low + (high - low) / 2;
            if (nums[pivot] < nums[high]) {
                high = pivot;
            }
            else if (nums[pivot] > nums[high]) {
                low = pivot + 1;
            }
            else {
                high -= 1;
            }
        }
        return nums[low];       
    }

    int falseFindMin(vector<int>& nums){
        int low = 0;
        int high = nums.size() - 1;
        while (low <= high) {       // 这个直接改掉也没有关系， 为什么？？？TODO
            int pivot = low + (high - low) / 2;
            if (nums[pivot] < nums[high]) {
                high = pivot;
            }
            else if (nums[pivot] > nums[high]) {
                low = pivot + 1;
            }
            else {
                high -= 1;
            }
        }
        return nums[low];               
    }
};
/**
 * @description: 
 * @param {*}
 * @return {*}
 */
class Solution1{
public:
    int findMin(vector<int>& nums){
        return findMin(nums, 0, nums.size() - 1);
    }

    int findMin(vector<int>& nums, int left, int right){
        if(nums[right] > nums[left] || left == right)
            return nums[left];
        int mid = left + (right - left)/2;
        return min(findMin(nums, left, mid), findMin(nums, mid+1, right));
    }
};


int main(){
    Solution sl;
    // vector<int> vec = {2,2,2,0,1};
    vector<int> vec = {3,1,3};
    cout << sl.falseFindMin(vec) << endl;
    
}
