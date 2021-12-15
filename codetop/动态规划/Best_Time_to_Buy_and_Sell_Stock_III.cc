/*
 * @Date: 2021-12-08 13:50:18
 * @LastEditors: kafier
 * @LastEditTime: 2021-12-08 13:53:19
 */
#include <vector>
using namespace std;
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int buy1 = -prices[0], buy2 = -prices[0];
        int sell1 = 0, sell2 = 0;
        int len = prices.size();
        for (int i = 0; i < len; ++i)
        {
            buy1 = max(buy1, -prices[i]);
            sell1 = max(sell1, buy1 + prices[i]);
            buy2 = max(buy2, sell1 - prices[i]);        //如果在price最大的时候进行第二次买入是不可能的， 这样会打回buy1。 但是如果说是有新的投资机会， buy2可以保持上一次的sell1的状态进行购买
            sell2 = max(sell2, buy2 + prices[i]);       //而这样的话， sell2 就会保持和sell1同样的价格。
        }
        return sell2;
    }
};

int main()
{
    vector<int> nums = {3,3,5,0,0,3,1,4};
    Solution sl;
    sl.maxProfit(nums);


}