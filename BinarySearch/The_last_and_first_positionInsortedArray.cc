#include <vector>
#include <iostream>
using namespace std;
// 34. 在排序数组中查找元素的第一个和最后一个位置
class Solution {
public:
    // 先使用二分查找， 查找到后使用双指针分流到前后两端
    vector<int> searchRange(vector<int>& nums, int target) {
        int index = themidIndex(nums, target);
        vector<int> res(2, -1);
        // if(nums.size() == 1 && target == nums[0]){
        //     res[0] = 0;
        //     res[1] = 0;
        //     return res;
        // }
        if(nums.size() == 0 || nums[index] != target ){
            return res;
        }
        int left = index, right = index;

        while(left >= 0 && nums[left] == target){
            --left;
        }
        while(right < nums.size() && nums[right] == target){
            ++right;
        }
        res[0] = left+1;
        res[1] = right-1;
        return res;
    }

    int themidIndex(vector<int>& nums, const int& target){
        int left = 0, right = nums.size()-1;
        while(left < right){
            int mid = left + (right-left)/2;
            if(target == nums[mid]){
                return mid;       
            }
            else if(target > nums[mid]){
                left = mid+1;
            }
            else{
                right = mid;
            }
        }
        return left;
    }
};
int main(){
    vector<int> input = {1};
    Solution sl;
    for(auto ele:sl.searchRange(input, 1)){
        cout << ele << endl;
    }
}