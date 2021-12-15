/*
 * @Date: 2021-12-02 11:57:56
 * @LastEditors: kafier
 * @LastEditTime: 2021-12-04 11:28:32
 */
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * @description:
     *  由于都是正整数， 所以可以直接把大于target 的数给过滤了 
     *  可以重复选择同一个选项
     * @param {int} target
     * @return {*}
     */
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtracks(candidates, target, 0);
        return ret;
    }
        
    void backtracks(vector<int>&  candidates, int target, int cur){
        if(cur >= candidates.size() && target <0 ){
            return;
        }
        if(target == candidates[cur]){
            //满足总和
            ret.emplace_back(path);
            return;
        }
        
        // 不选择这个选项
        backtracks(candidates, target, cur+1);
        path.emplace_back(candidates[cur]);
        backtracks(candidates, target-candidates[cur], cur);
        // backtracks(candidates, target-candidates[cur], cur+1); 没必要再写这个回溯了， 因为已经给它去跳过当前数的选项。 即便是它之前选过了， 也可以直接使用那个区跳过
        path.pop_back();
    }

    vector<vector<int>> ret;
    vector<int> path;
};

int main(){
    vector<int> input = {2,3,6,7};
    int target = 7;
    Solution sl;
    sl.combinationSum(input, target);
}