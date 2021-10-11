// 31. 下一个排列
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // 直观模拟  不可行
        // 数学方法思考
        int len = nums.size();
        int left = 0, right = 0;
        int i = len-2;
        while(i >= 0 && nums[i] >= nums[i+1]){
            i--;
        }

        if(i >= 0){
            int j = len - 1;
            while(j >= 0 && nums[i] >= nums[j]){
                --j;
            }
            swap(nums[i], nums[j]);
        }

        reverse(nums.begin()+i+1, nums.end());

    }
};

// 1 2 3 4
// 1 2 4 3 

// 2 1 4 3
// 2 3 4 1 ---  2 3 1 4

// 4 3 2 1
// 1 2 3 4
// 要找到靠右边较小的数字（这个数字尽可能靠右， 那么从右边遍历, 找到第二小的数
// 再从右边到上面找到的数字为界， 要找到靠右边较小的数字（这个数字尽可能小， 那么从右边遍历，遍历到非递减序列为止
// 再从右边到上面找到的数字为界， 找到最小的较大数，与之交换
// 由于之前的第一步操作， 我们可以断定 i 之后的数字是降序排序， 而后我们将之reverse 就变为 升序排序了

int main(){
    Solution sl;
    vector<int> input = {4,3,2,1};
    sl.nextPermutation(input);
}