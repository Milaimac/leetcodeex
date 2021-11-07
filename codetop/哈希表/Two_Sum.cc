/*
 * @Date: 2021-11-07 21:00:01
 * @LastEditors: kafier
 * @LastEditTime: 2021-11-07 22:34:28
 * @FilePath: /leetcodeex/codetop/哈希表/Two_Sum.cc
 */
#include <vector>
#include <unordered_map>
#include <map>
#include <unordered_set>
using namespace std;

/**
 * @description: 
 *  1. 可以先把nums中大于target的数过滤掉
 *  2. 要注意不能够将自己给重复利用， 比如 {3,3}  target = 6
 * @param {*}
 * @return {*}
 */
class Solution
{
public:
    // 同一个元素不能在答案中重复出现， 只有一个答案
    // 题目是要返回下标
    vector<int> twoSum(vector<int> &nums, int target)
    {
        // unordered_set<int> thelastNum;
        unordered_map<int, int> thelastNum;
        int len = nums.size();
        for(int i = 0;i < len;++i){
            if(!thelastNum.count(target-nums[i])){
                thelastNum[target-nums[i]] = i;                     
            }
        }
        vector<int> res(2);
        for(int j = len-1;j >= 0;--j){
            if(thelastNum.count(nums[j])){
                if( thelastNum[nums[j]] == j){
                    continue;
                }
                res[0] = j;
                res[1] = thelastNum[nums[j]];
                break;
            }
        }

        return res;
    }
};
/**
 * @description: 
 *  直接一次遍历
 *  因为从左到右遍历自然能够产生对应的哈希表， 而能够+= target 的数， 必然会在后面， 
 *  所以采取一次遍历的做法， 减少时间复杂度和空间复杂度
 * 
 * @param {*}
 * @return {*}
 */
class Solution1{
public:
    vector<int> twoSum(vector<int> &nums, int target){
        int len = nums.size();
        unordered_map<int, int> theLastNum;
        for(int i = 0;i < len;++i){
            auto it = theLastNum.find(target - nums[i]);        
            if(it != theLastNum.end()){
                return  vector<int>{it->second, i};
            }
            theLastNum[nums[i]] = i;
        }
        return vector<int> {};
    }
};