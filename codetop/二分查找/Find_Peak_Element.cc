/*
 * @Date: 2021-12-04 12:01:41
 * @LastEditors: kafier
 * @LastEditTime: 2021-12-04 12:25:50
 */
#include <vector>
using namespace std;
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while(left < right){
            int mid = left + (right - left) / 2;
            if(nums[mid] < nums[mid+1]){
                left = mid+1;
            } 
            else{
                right = mid;
            }
        }
        return left;
    }
};