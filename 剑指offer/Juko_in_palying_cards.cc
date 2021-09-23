// 剑指 Offer 61. 扑克牌中的顺子
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
class Solution {
public:
    bool isStraight(vector<int>& nums) {
        set<int> norepeat;
        for(int i = 0;i < nums.size();++i){
            if(nums[i] == 0){
                continue;
            }

            if(norepeat.count(nums[i])){
                return false;
            }
            norepeat.insert(nums[i]);
        }
        int maxele = *max_element(norepeat.begin(), norepeat.end());
        int minele = *min_element(norepeat.begin(), norepeat.end());
        return (maxele - minele) < 5;
    }
};
// 大小王0 可以 看成任意数字， 所以这里的思路是，将0跳过
// 计算最大值和最小值的距离小于5
// 并且使用set去重
