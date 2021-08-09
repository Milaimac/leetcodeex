#include"head.h"
class Solution {
public:
    bool makeflowers(vector<int>& bloomDay, int k, int m, int days){
        int flowers = 0, sum = 0;
        for(int i=0;i<bloomDay.size();i++){
            if(days >= bloomDay[i]){
                flowers++;
                if(flowers == k){
                    sum++;
                    flowers = 0;
                }
            }
            else{
                flowers = 0;
            }
        }
        return sum >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        if(m*k > bloomDay.size()){
            return -1;
        }
        // 二分法，怎么二分？当在（0 - nums）无法完制作花束，（nums - max_elemet(bloomday)) 能够制作花束。
        int low = 1,high = *max_element(bloomDay.begin(), bloomDay.end());
        while(low < high){
            int mid = (low+high)/2;
            if(makeflowers(bloomDay, k,m, mid)){
                high = mid;
            }else{
                low = mid + 1;
            }
        }   
        return high;
    }
};