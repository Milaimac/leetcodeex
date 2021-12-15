/*
 * @Date: 2021-12-04 11:29:38
 * @LastEditors: kafier
 * @LastEditTime: 2021-12-04 11:58:18
 */
#include <vector>
using namespace std;
class Solution
{
public:
    //p
    /**
     * @description: 
     * 想要知道面积， 其实是想要知道边长，  想要知道边长， 可以通过dp
     * 而这个边长必然是
     * @param {*}
     * @return {*}
     */
    int maximalSquare(vector<vector<char>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size();
        if (matrix.size() == 0 || matrix[0].size() == 0)
        {
            return 0;
        }
        vector<vector<int>> dp(m, vector<int>(n));
        int maxlen = 0;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (matrix[i][j] == '1')
                {
                    if (i == 0 || j == 0)
                    {
                        dp[i][j] = 1;
                    }
                    else{
                        
                        dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                    }
                    maxlen = max(maxlen, dp[i][j]);   
                }
            }
        }
        return maxlen * maxlen;
    }
};