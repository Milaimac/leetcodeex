/*
 * @Date: 2021-11-09 22:18:21
 * @LastEditors: kafier
 * @LastEditTime: 2021-11-10 14:00:07
 * @FilePath: /leetcodeex/codetop/数组/3Sum.cc
 */
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    /**
     * @description: 
     *  不包含重复解 导致 如果是直接暴力， 而最后还要放入哈希表进行去重操作， 得到不包含重复三元组的最终答案
     *  【不重复】的本质是什么？
     *  只要做到
     *          第二重循环枚举到的元素不小于当前第一重循环枚举到的元素
     *          第三重循环枚举到的元素不小于当前第二重循环枚举到的元素
     *  只要保证 a <= b <= c ， 那么就只有(a,b,c)这个顺序了
     * 对每一重循环而言， 相邻两次枚举的元素不能相同
     * nums.sort()
        for first = 0 .. n-1
            // 只有和上一次枚举的元素不相同，我们才会进行枚举
            if first == 0 or nums[first] != nums[first-1] then
                for second = first+1 .. n-1
                    if second == first+1 or nums[second] != nums[second-1] then
                        for third = second+1 .. n-1
                            if third == second+1 or nums[third] != nums[third-1] then
                                // 判断是否有 a+b+c==0
                                check(first, second, third)‘
     * 如何跳出三重循环的大框架， 如果我们固定了前两重循环枚举到的元素a和b， 那么只有唯一的c， 满足 a+b+c = 0 。 当二重循环往后枚举一个元素b'时  a + b + c > 0 ， 那么要满足它等于0 ， c就需要往前面移动， 说明了
        二重和三重循环其实是并列的。 

     *  所以这里就采用了双指针的做法， 一个是二重循环的， 一个是三重循环的
     * @param {*}
     * @return {*}
     */
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for(int first = 0;first < n;++first){
            if(first > 0 && nums[first] == nums[first-1]){
                continue;
            }
            // c对应的指针初始指向数组的最右端
            int third = n-1;
            int target = -nums[first];
            for(int second = first + 1;second < n; ++ second){
                if(second > first+1 && nums[second] == nums[second-1]){
                    continue;
                }
                while(second < third && nums[second] + nums[third] > target){
                    --third;
                }
                if(second == third){
                    break;
                }
                if(nums[second] + nums[third] == target){
                    ans.push_back({nums[first], nums[second], nums[third]});
                }
            }
        }
        return  ans;
    }
};