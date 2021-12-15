/*
 * @Date: 2021-12-05 14:35:23
 * @LastEditors: kafier
 * @LastEditTime: 2021-12-05 17:31:08
 */
#include <vector>
using namespace std;
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> tmp(n);
        return mergeSort(nums, tmp, 0, n-1);
    }
    // 这个确实和普通的归并排序有所不同， 这里要返回一个整型： 这个整型是[left, right]区间中的逆序对的数量
    // 这里最为关键的地方是只有在 左区间的数 小于 右区间的数， 我们才需要更新inverse_count(inv_count)。 
    // 如果在右区间的数 小于 左区间的数， 尽管这是一个逆序对。 但是我们没法总结出前面的情况， 因此不如一口气将之前
    int mergeSort(vector<int>& nums, vector<int>& tmp, int l, int r)
    {
        if(l >= r){
            return 0;
        }

        int mid = (l + r) / 2;
        int inv_count = mergeSort(nums, tmp, l, mid) + mergeSort(nums, tmp, mid+1, r);  
       
        int i = l, j = mid + 1, pos = l;
        while(i <= mid && j <= r)
        {
            if(nums[i] <= nums[j]){
                tmp[pos] = nums[i];
                ++i;
                inv_count += (j - (mid + 1));
            }
            else{
                tmp[pos] = nums[j];
                ++j;
            }
            ++pos;  
        }

        for(int k = i;k <= mid;++k)
        {
            tmp[pos++] += nums[k];
            inv_count += (j - (mid + 1));
        }

        for(int k = j;k <= r;++k)
        {
            tmp[pos++] = nums[k];
        }
        copy(tmp.begin() + l, tmp.begin() + r + 1, nums.begin() + l);
        return inv_count;
    }
};