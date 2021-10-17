#include <vector>
using namespace std;

class Solution {
public:

    // 这道题 只需要 将0，1，2， 排序

    // 比较直接的想法就是将0 和 1排到前面去
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int ptr = 0;
        for(int i = 0;i<n;++i)
        {
            if(nums[i] == 0)
            {
                swap(nums[i], nums[ptr]);
                ++ptr;
            }
        }

        for(int i = ptr;i<n;++i)
        {
            if(nums[i] == 1)
            {
                swap(nums[i], nums[ptr]);
                ++ptr;
            }
        }
    }
    // 
    // 使用快速排序的子过程 partition 
    //
    // nums[0 , .... , n-1]
    // partition 就是把整个数组分为三个部分， 一个部分是小于pivot 一个部分是等于pivot 一个部分是大于pivot
    // 
    // 那么这道题就是以1为pivot的
    // 
    // 循环不变量 
    // all in [0, p0) == 0;
    // all in [p0, i) == 1
    // all in (p2, len-1] == 2
    // 如果循环不变量p2和p2的定义是这样的话， 那么通过观察i和p2之间是有个数没有遍历到， 那么就可以使得i <= p2
    void sortColorsV1(vector<int>& nums)
    {
        int len = nums.size();
        int p0 = 0, p2 = len-1;
        int i = 0;
        if(len < 2)
            return;
        while(i <= p2)
        {
            if(nums[i] == 0)
            {
                // nums[i] == 0, 而等于0 的数应该在循环不变量p0的左边
                swap(nums[i], nums[p0]);
                ++i;
                ++p0;
            }
            else if(nums[i] == 1)
            {
                ++i;
            }
            else
            {
                swap(nums[i], nums[p2]);
                --p2;
            }
        }
        
    }

    // 循环不变量 
    // all in [0, p0] == 0;
    // all in (p0, i) == 1
    // all in [p2, len) == 2


    // 如果修改成这样，那么p0就应该从-1开始
    void sortColorsV11(vector<int>& nums)
    {
        int len = nums.size();
        int p0 = -1;    //p0  从-1开始
        int p2 = len;   //p2 从len开始
        int i = 0;
        if(len < 2)
            return;
        while(i < p2)
        {
            if(nums[i] == 0)
            {
                // nums[i] == 0, 而等于0 的数应该在循环不变量p0的左边
                ++p0;
                swap(nums[i], nums[p0]);
                ++i;
            }
            else if(nums[i] == 1)
            {
                ++i;
            }
            else
            {
                --p2;
                swap(nums[i], nums[p2]);
            }
        }        
    }


};
