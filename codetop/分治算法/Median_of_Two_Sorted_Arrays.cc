/*
 * @Date: 2021-11-25 14:48:57
 * @LastEditors: kafier
 * @LastEditTime: 2021-11-25 14:55:06
 */
#include <vector>
using namespace std;
class Solution {
public:
 
    /**
     * @description: 
     *  要找到k 个元素， 可以比较A[k/2] 和 B[k/2]， 由于A[k/2-1]和B[k/2-1] 的前面分别有A[0 .. k/2-2] 和 B[0 .. k/2-2] ，
     *  即每个数字中有 k/2 -1 个元素，当A[k/2-1]和B[k/2-1]得到其中的最小值， 最多只有 (k/2-1) + (k/2-1) = k-2个元素比它小，那么它就不能是第k小的数
     *  
     * @param {*}
     * @return {*}
     */
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
    }
};