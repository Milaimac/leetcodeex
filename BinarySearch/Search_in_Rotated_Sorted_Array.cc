#include <vector>
#include <iostream>
using namespace std;


// mid 左右两边， 必定有一边是有序的，
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size(); 
        int left = 0, right = len-1;

        if(len == 0)    return -1;
        if(len == 1)    return nums[0] == target ? 0 : -1;
        while(left < right)
        {
            
            int mid = left + (right-left)/2;
            if(target == nums[mid]){
                return mid;
            }
            if(nums[0] <= nums[mid]){
                // it means the left intevals is sorted
                // if(target < nums[mid]){          // must ensure the target is in the left sorted intervals
                if(nums[0] <= target && target < nums[mid]){
                    right = mid-1;
                }
                else{
                    left = mid+1;
                }
            }
            else
            {
                if(nums[mid] < target && target <= nums[len-1])
                {
                    left = mid+1;
                }
                else
                {
                    right = mid-1;
                }
            }
        }

        return -1;
    }
};