#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

// md， 一个看起来这么简单的题，却有那么多骚操作

// 哈希表就不说了
// 如果是排序， 直接选排序后数组 的中位数就是要的数， 毕竟该数的数量超过了 n/2
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        return nums[n/2];
    }
    // 分治
    // 如果数 a 是数组nums的众数， 如果我们将 nums 分成两部分， 那么 a 必定是至少一部分的众数， 
    // 反证法 如果数a不是其中一部分的众数， 那么设数组的长度为n,也就是说 a 出现的次数 小于 left/2 + right/2，其中left + right = n;
    // 所以我们可以采取分治法解决这个问题

};


// 时间复杂度为 O(nlog(n))
// 空间复杂度为 O(nlog(n)) 递归的话， 也会开辟堆区
class SolutionV1
{
public:
    int count_to_range(vector<int>& nums, int target,int left, int right)
    {   
        int count = 0;
        for(int i = left;i < right;++i)
        {
            if(nums[i] == target)
            {
                ++count;
            }
        }
        return count;
    }
    int majorrity_ele_rec(vector<int>& nums, int left, int right)
    {
        if(left == right)
        {
            return nums[left];
        }
        int mid = left + (right-left)/2;
        int left_major = majorrity_ele_rec(nums, left, mid);
        int right_major = majorrity_ele_rec(nums, mid+1, right);
        // 这个count_to_range指的是要计算是不是当前的众数
        if(count_to_range(nums, left_major, left, right) >= (right-left+1)/2){
            return left_major;
        }
        if(count_to_range(nums, right_major, left, right) >= (right-left+1)/2)
        {
            return right_major;
        }
        return -1;
    }
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        return majorrity_ele_rec(nums, 0, n);
    }
};

// Boyer-Moore 投票算法
// 如果我们把众数记为 +1， 把其他数记为-1， 将它们加起来， 显然和大于0
// 遍历数组 num 中的所有元素， 对于每个元素x， 在判断x之前， 如果count 的值为0 ， 那我们将值赋给candidate， 随后我们判断x
// 如果x不等于candidate， 那么count--
// 如果x 等于 candidate， 那么count++
class SolutionV2
{
public:
    int majorityElement(vector<int>& nums) {
        int candidate = -1;
        int count = 0;
        for(auto& num:nums)
        {
            if(count == 0)
            {
                candidate = num;
            }
            if(num == candidate)
            {
                count++;
            }
            else
            {
                --count;
            }
        }

        return candidate;
    }
};
int main()
{
    vector<int> vec = {3,2,3};
    SolutionV2 sl;
    cout << sl.majorityElement(vec) << endl;
}