/*
 * @Date: 2021-12-03 11:00:13
 * @LastEditors: kafier
 * @LastEditTime: 2021-12-03 11:02:39
 */
#include <vector>
using namespace std;
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int MAX = amount + 1;
        vector<int> dp(MAX, MAX);
        dp[0] = 0;
        for(int i = 1;i <= amount;++i){
            for(auto& coin : coins){
                if(i < coin){
                    continue;
                }
                dp[i] = min(dp[i-coin]+1, dp[i]);
            }
        }
        return dp[amount] == MAX ? -1 : dp[amount];
    }
};