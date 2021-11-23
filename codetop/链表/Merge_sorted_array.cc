/*
 * @Date: 2021-11-22 21:50:06
 * @LastEditors: kafier
 * @LastEditTime: 2021-11-22 22:09:10
 */
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * @description: 
     * 通过顺序的双指针， 将最小的值存到另一个数组， 而后再放到nums1
     * @param {int} m
     * @param {int} n
     * @return {*}
     */
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = 0, p2 = 0;
        int sorted[m+n];
        int cur;
        while(p1 < m || p2 < n){
            if(p1 == m){
                cur = nums2[p2++];
            }
            else if(p2 == n){
                cur = nums1[p1++];
            }
            else if(nums1[p1] < nums2[p2]){
                cur = nums1[p1++];
            }
            else{
                cur = nums2[p2++];
            }
            sorted[p1+p2-1] = cur;
        }

        for(int i = 0;i < m+n;++i){
            nums1[i] = sorted[i];
        }
    }

    /**
     * @description:逆向双指针  
     * 顺向双指针中， 之所以要创建临时数组， 是因为如果直接合并到nums1中， nums1中的数组可能在取出之前被覆盖， 但是我们观察知道， num1中的后半部分是空的， 可以直接覆盖， 
     * @param {int} m
     * @param {int} n
     * @return {*}
     */
    void merge1(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m -1, p2 = n-1;
        int tail = m + n - 1;
        int cur;
        while(p1 >= 0 || p2 >= 0){
            if(p1 == -1){
                cur = nums2[p2--];
            }else if(p2 == -1){
                cur = nums1[p1--];
            }
            else if(nums1[p1] > nums2[p2]){
                cur = nums2[p2--];
            }
            else{
                cur = nums1[p1--];
            }
            nums1[tail--] = cur;
        }
    }
};