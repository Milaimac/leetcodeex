#include<iostream>
#include<vector>
using namespace std;
// 1109. 航班预订统计
// 如果是单纯的暴力加法，必然会超时，因此采用差分的办法来解决这个问题
// 由于booking[0]到booking[1]都是要加上booking[2]的，因此比起一次一次加入，不如等凑好了再去加
// 先把booking[0]的满上，由于booking[1]后便不加了，那么差分数组便应该是减去这个数booking[2]，最终再有前面的不断累加
// 这总算法的复杂度为O(n+booking.size())
// 而暴力法是o(n^m)
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        // int m = bookings.size();
        vector<int> nums(n);
        for(auto & booking:bookings){
            nums[booking[0] - 1] += booking[2];
            if(booking[1] < n)
            {
                nums[booking[1]] -= booking[2];
            }
        }
        for(int i = 1;i<n;i++){
            nums[i] += nums[i-1];
        }   
        return nums;
    }
};