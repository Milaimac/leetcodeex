#include <vector>
using namespace std;
class Solution {
public:
    //先来一发暴力
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> res;
        for(int i = 1; i<=target/2;++i){
            int sum = i;
            for(int j = i+1;j < target;++j){
                sum += j;
                if(sum == target){
                    vector<int> tmp;
                    for(int k = i;k<=j;++k){
                        tmp.emplace_back(k);
                    }   
                    res.emplace_back(tmp);
                    break;
                }
                else if(sum > target){
                    break;
                }
            }
        }
        return res;
    }
};
// 从小到大排列
// 连续的
class SolutionV1 {
public:
    // 尝试使用滑动窗口来做
    vector<vector<int>> findContinuousSequence(int target) {
        int low = 1, high = 2;
        vector<vector<int>> res;
        while(low < high && high < target){
            int sum = 0;
            if((high-low+1)%2 == 1){
                //it means 奇数
                sum = (high+low)*((high-low+1)/2) + (high+low)/2;
            }
            else{
                sum = (high+low)*((high-low+1)/2);
            }

            if(sum < target){
                ++high;
            }
            else if(sum == target){
                vector<int> ans;
                for(int i = low;i<=high;++i){
                    ans.emplace_back(i);
                }
                res.emplace_back(ans);
                // 最终找到这里没有加入low++
                ++low;
            }
        }
        return res;
    }
    // return res;
};

int main(){
    SolutionV1 sl;
    sl.findContinuousSequence(9);
}