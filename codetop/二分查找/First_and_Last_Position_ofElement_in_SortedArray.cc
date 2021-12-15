/*
 * @Date: 2021-12-02 11:34:05
 * @LastEditors: kafier
 * @LastEditTime: 2021-12-02 11:37:00
 */
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
// O(logn) 只能是二分查找了
// 可以通过二分找到最前面的一个位置。 但是接下来不能够直接遍历到最后一个， 万一有个示例是全部都是一个数，就变成了O(n)
    vector<int> searchRange(vector<int>& nums, int target) {
        auto it1 = lower_bound(nums.begin(), nums.end(), target);
        auto it2 = upper_bound(nums.begin(), nums.end(), target);
        
        int first = it1 - nums.begin();
        int last = it2 - nums.begin() -1;
        return {first, last};
    }

};