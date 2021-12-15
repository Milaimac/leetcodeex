/*
 * @Date: 2021-12-02 12:30:54
 * @LastEditors: kafier
 * @LastEditTime: 2021-12-04 11:28:30
 */
#include <vector>
using namespace std;
class Solution {
public:
    /**
     * @description: 
     * @param {*}
     * @return {*}
     */
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size();
        int len = nums.size();
        while(left < right)
        {
            int mid = left + (right - left) / 2;
            if(nums[mid] > nums[len]){
                //it means it in the left place
                left = mid+1;
            }else{
                right = mid;
            }
        }
        return left;
    }   
};