/*
 * @Date: 2021-12-01 16:08:07
 * @LastEditors: kafier
 * @LastEditTime: 2021-12-01 16:50:47
 */
#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
    /**
     * @description: 
     * 应该可以是双串dp
     * 使用dp[i][j] 表示字符串s中从i开始到j结束的最长回文字符串。 注意到这个不是要返回长度， 而是要返回字符串。 
     * 动态转移方程 dp[i][j] = if(s[i] == s[j]) dp[i][j] = dp[i][j]+1; else dp[i][j];
     * 初始化条件。 d
     * 
     * @param {string} s
     * @return {*}
     */
    string longestPalindrome(string s)
    {
        int n = s.size();
        if (n < 2)
        {
            return s;
        }

        int maxlen = 1;
        int begin = 0;
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = 0; i < n; ++i)
        {
            dp[i][i] = true;
        }

        for (int len = 2; len <= n; ++len)
        {
            for (int i = 0; i < n; ++i)
            {
                int j = len + i - 1;
                if(j >= n)
                {
                    break;
                }

                if(s[i] != s[j])
                {
                    dp[i][j] = false;
                }
                else{
                    if(j - i < 3){
                        dp[i][j] = true;    // 如果只有两个数, 不适合进入到dp[i+1][j-1]的状态
                    }
                    else{
                        dp[i][j] = dp[i+1][j-1];
                    }
                }
            
                if(dp[i][j] && j-i+1 > maxlen){
                    maxlen = j-i+1;
                    begin = i;
                }
            }
        }
        return s.substr(begin, maxlen);
    }
};