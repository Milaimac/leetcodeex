/*
 * @Date: 2021-11-30 14:29:57
 * @LastEditors: kafier
 * @LastEditTime: 2021-12-01 14:50:08
 */
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    /**
     * @description: 
     * 三个操作是等价的
     * 在word1插入一个和在word2删除一个是等价的。 word1 = "dog", word2="doge"
     * 同理， 在word1删除一个和word2插入一个是等价的， 
     * 在word1换一个和在word2换一个是等价的
     * 
     * 这样，整体的操作就简化为
     * 在单词A中插入一个字符
     * 在单词B中插入一个字符
     * 修改单词A的一个字符
     * 执行插入操作， 那么比较word1[0 ... i] 和 word2[0 .. j-1]的结果（让word1[i+1]和 word2[j]相等)
     * 执行删除操作, 那么比骄wrod1[0 ... i-1] 和 word2[0 ... j]的结果
     * 执行替换操作。 那么比较word1[0 ... i-1] 和 word2[0 ... j-1]的结果
     * 
     * 动态规划数组意义， dp[i][j] 表示 word1[0 .. i]和 word2[0 ... j]的匹配情况， 为了更好的初始化条件， 不如多设个空字符
     * dp[0][0] 表示两者为空
     * 
     * 那么初始话条件就可以是从word1为空字符变为word2的编辑次数
     * @param {string} word1
     * @param {string} word2
     * @return {*}
     */
    int minDistance(string word1, string word2)
    {
        int n = word1.length();
        int m = word2.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1));
        for(int j = 1;j < m;++j){
            dp[0][j] = dp[0][j-1] +1;
        }

        for(int i = 1;i < n;++i){
            dp[i][0] = dp[i-1][0] + 1;
        }

        for(int i = 1;i <= n;++i){
            for(int j = 1;j <= m;++j)
            {
                if(word1[i-1] == word2[j-1])    
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j]));
            }
        }
        return dp[n][m];
    }
};