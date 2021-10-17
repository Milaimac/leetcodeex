#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
// 4. 寻找两个正序数组的中位数
class Solution {
public:
// 最简单的方法，就是将两个数组给合并了， 然后排序， 
// 得到其中的中位数
// 时间复杂度为O(m+n) , o(m+n)

// 第二种比较能偶容易想到的就是 计算出中位数的索引， 然后使用双指针遍历其中每个数组的较小数，并递增指针，直到中位数
// 如果说是奇数 那么遍历到中位数就ok了， 如果说是偶数， 还需要进行相加除2
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0;
        int m = nums1.size(), n = nums2.size();

        int mid;
        if((m+n)%2 == 1)
        {
            mid = (m+n)/2;
        }
        else
        {
            mid = (m+n+1)/2;    //这里选择了比较大的数
        }
        // 如果有空的数组， 那么就跳过它
        if(m == 0)
        {
            return (m+n)%2 == 1 ? nums2[mid] : (nums2[mid] + nums2[mid-1])/2.0;
        }
        else if(n == 0)
        {
            return (m+n)%2 == 1 ? nums1[mid] : (nums1[mid] + nums1[mid-1])/2.0;            
        }
        // 使用 两个数字存储mid和mid-1， 
        vector<int> temp(2);
        for(int idex = 0;idex <= mid;++idex)
        {   
            // 如果其中一个数组已经用完了
            if(i == nums1.size() )
            {
                temp[idex%2]  = nums2[j];
                ++j;
            }
            else if(j == nums2.size())
            {
                temp[idex%2] = nums1[i];
                ++i;
            }
            else if(nums1[i] <= nums2[j])
            {
                temp[idex%2] = nums1[i];
                ++i;
            }
            else{
                temp[idex%2] = nums2[j];
                ++j;
            }
        }

        return (m+n)%2 == 1 ? (temp[1] > temp[0] ? temp[1] : temp[0]) : (temp[1]+temp[0])/2.0;
    }
    // 如何将时间复杂度 降为O(log(m+n))

    // 这道题可以转化为寻找两个有序数组中的第k小的数， 其中k 为(m+m)/2 或 (m+n)/2 + 1

    // 要找到k 个元素， 可以比较A[k/2] 和 B[k/2]， 由于A[k/2-1]和B[k/2-1] 的前面分别有A[0 .. k/2-2] 和 B[0 .. k/2-2] ，
    // 即k/2-1个元素， 对于A[k/2 - 1] 和 B[k/2 -1] 中的较小值， 最多只有(k/2 - 1) + (k/2 - 1) <= k-2 元素比它小，那么它就不能是第k小的数了
    // 由此归纳出三种情况
    // 如果A[k/2 - 1] < B[k/2 - 1]， 则比A[k/2 -1]小的数最多只有A的前k/2-1个数和B的前k/2-1个数
    // 即比A[k/2-1]小的数只有k-2个， 所以A[0] 到 A[k/2-1]也不可能是k个数， 可以全部排除

    // 如果A[k/2-1] > B[k/2-1], 就可以排除掉B[0] 和 B[k/2-1]

    // 同第一种情况

    // 三种情况需要特殊处理
    // 如果A[k/2-1] 或者 B[k/2-1] 越界， 那么我们选取对于数组的最后一个元素， 在这种情况下， 必须根据排除数的个数来删除， 而不是 直接删除K-2
    // 如果数组为空， 那么直接返回这个数组中第k小的数就可以了    
    double findMedianSortedArraysV1(vector<int>& nums1, vector<int>& nums2) {
        int total = nums1.size() + nums2.size();
        if(total% 2 == 1)
        {
            return getKElement(nums1, nums2, total/2);
        }
        else
        {
            return (getKElement(nums1, nums2, total/2) + getKElement(nums1, nums2, total/2+1))/2.0;
        }
    }
    // 得到第k个数
    int getKElement(vector<int>& nums1, vector<int>& nums2, int k)
    {
        // 先考虑边界情况
        int m = nums1.size();
        int n = nums2.size();

        int index1 = 0, index2 = 0;

        while(true)
        {
            if(index1 == m)
            {
                //已经遍历完nums1
                return nums2[index2+k-1];
            }
            if(index2 == n)
            {
                return nums1[index1+k-1];
            }
            // 说明k 到了 对应的index
            if(k == 1)
            {
                return min(nums1[index1], nums2[index2]);
            }

            // 选取 k/2 和 整个数组的长度
            int newIndex1 = min(index1+k/2-1, m);
            int newIndex2 = min(index2+k/2-1, n);

            int pivot1 = nums1[newIndex1];
            int pivot2 = nums2[newIndex2];
            if(pivot1 <= pivot2)
            {   //这里先是确定k的位置，通过这个确定对应的位置
                k -= newIndex1 - index1 + 1;
                index1 = newIndex1 + 1;
            }
            else
            {
                k -= newIndex2 - index2 + 1;
                index2 = newIndex2 + 1;
            }
        }
    }

};


int main()
{
    Solution sl;
    vector<int> vec1  = {2};
    vector<int> vec2 = {};
    cout << sl.findMedianSortedArrays(vec1, vec2) << endl; 

}