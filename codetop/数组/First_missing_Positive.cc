/*
 * @Date: 2021-12-01 21:48:01
 * @LastEditors: kafier
 * @LastEditTime: 2021-12-01 22:47:45
 */
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @description: 
     * 缺失的第一个正整数只能出现在[0---n]之间， 当0--n之间没有空缺的正整数， 答案就是n+1
     * 否则就是其中第一个缺失的数
     * 
     * 实际上对于一个长度为N的数组。 其中没有出现的最小整数只能在[1, N +1]中， 这是因为如果[1, N]都出现了， 那么答案就是N+1， 否则答案是[1, N]中没有出现的最小正整数。 
     * 这样一来，在[1, N]范围内的数放入哈希表中， 也可以得到最终的答案。
     * 
     * 遍历数组。 如果在[1, N]中的范围内， 那么就将数组中的第x-1个位置打上标记。 如果都被打上了标记， 那么答案是N+1， 否则答案是最小的没有打上标记的位置加1（这就是利用数组本身作为哈希表）
     * 
     * 如何设计标记
     * 1. 将所有小于等于0的数修改为 N + 1
     * 2. 遍历数组中的每一个数x， 如果已经被打了标记， 因此原本对应的数|x|， 如果|x|在[1,N]范围内。那我们在数组中的第|x|-1个位置的数添加一个负号。 注意如果它有负号， 不需要重复添加。
     * @param {*}
     * @return {*}
     */
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int & num:nums){
            if(num <= 0){
                num = n+1;
            }
        }
        for(int i = 0;i < n;++i){
            int num = abs(nums[i]);
            //如果存在这个n里面的数， 那么将对应的索引设置-1， 这可以表明对应的数字存在过
            if(num <= n){
                nums[num - 1] = -abs(nums[num-1]);
            }
        }

        for(int i = 0;i < n;++i)
        {
            if(nums[i] > 0){
                return i+1;
            }
        }
        return n+1;
    }
};