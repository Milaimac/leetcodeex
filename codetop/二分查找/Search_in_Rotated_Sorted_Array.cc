/*
 * @Date: 2021-11-25 17:29:03
 * @LastEditors: kafier
 * @LastEditTime: 2021-11-25 18:54:57
 */
#include <vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        int n = nums.size();
        if(!n)  return -1;
        if(n == 1){
            return nums[0] == target ? 0 : -1;
        }
        while(left < right){
            int mid = left + (right-left)/2;
            // 判断mid在那个区段 
            // 在旋转区域的右边
            if(nums[mid] == target)
                return mid;
            // 判断出mid是在旋转数组的右边， （如果说没有旋转部分， 那么不会进入这个循环）
            // 判断出mid是旋转数组的右边之后， 思考什么情况mid会右移， 什么情况mid会左移
            // 如果target是在旋转数组的右边， 并且nums[mid] <= target， 那么就需要右移, 这里注意到数组中的各个元素互不相同(为了兼容没有旋转的情况， 只好写成target >= nums[0])
            // 否则就进行左移
            if(nums[mid] < nums[0]){
                // 接下来判断是否需要向右移动
                if(target <= nums[n-1] && nums[mid] < target){
                    left = mid+1;
                }
                else{
                    right = mid;
                }
            }
            // mid在旋转区域内（或者说没有旋转）
            // 思考如何移动，
            // 当target在旋转数组内， target > nums[n-1]并且nums[mid] > target,需要左移
            // 其他情况一律右移
            // 思考：那对于没有旋转的数组到底要怎么办
            else{
                // 在旋转区域内
                if(target >= nums[0] && target < nums[mid]){
                    right = mid;
                }
                else {
                    left = mid + 1;
                }
            }
        }
        return -1;
    }
};
class Solution1 {
public:
    int search(vector<int>& nums, int target) {
        int n = (int)nums.size();
        if (!n) {
            return -1;
        }
        if (n == 1) {
            return nums[0] == target ? 0 : -1;
        }
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) return mid;
            
            if (nums[0] <= nums[mid]) {
                if (nums[0] <= target && target < nums[mid]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            // 这个其实就是表示mid在非旋转数组的情况（一定会有旋转数组） 
            else {
                if (nums[mid] < target && target <= nums[n - 1]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
        return -1;
    }
};


int main(){

}