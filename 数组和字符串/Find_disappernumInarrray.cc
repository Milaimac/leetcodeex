#include <vector>
#include <iostream>
using  namespace std;
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        for(auto& num:nums){
            // x为索引
            int x = abs(num)-1;
            if(nums[x] > 0){
                nums[x] *= -1;         // 他把自己本来的位置 给占了，又要如何判断自己的这个位置原先是谁的？所以需要还原, 如果有重复的，则会负负得正。
            }
        }
        for(auto & num:nums){
            cout << num << " " ;
        }   
        cout << endl;

        for(int i = 0;i<nums.size();++i){
            if(nums[i] >0){
                res.push_back(i);
            }
        }
        return res;
    }
};


int main(){
    vector<int> input  = {4,3,2,7,8,2,3,1};
    Solution sl;
    sl.findDisappearedNumbers(input);

}