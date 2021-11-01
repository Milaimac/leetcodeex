#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
// 1011. 在 D 天内送达包裹的能力
// 使用二分查找， 估计船的最低载重能力
// 1. 首先货物中的最大重量 就是 船保底的载重能力，2. 所有货物的重量就是船最大的载重能力
// 2. 然后根据这个载重能力进行二分
class Solution{
public:
    int shipWithinDays(vector<int>& weights, int D){
        int left = *max_element(weights.begin(), weights.end());
        int right = accumulate(weights.begin(),weights.end(), 0);
        while(left < right){
            int mid = (left + right)/2;
            int need = 1,cur = 0;
            for(int weight:weights){
                if(cur + weight > mid){
                    ++need;
                    cur = 0;
                }
                cur += weight;
            }
            if(need <= D){
                right = mid;
            }
            else{
                left = mid+1;
            }
        }
        return right;
    }
};