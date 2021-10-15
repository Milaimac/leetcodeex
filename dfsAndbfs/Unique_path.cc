#include <vector>
#include <algorithm>
#include <iostream>
// 62. 不同路径
using namespace std;
class Solution {
public:
    // because the m and n <= 100 
    // 只能向下或者右移动

    // 先是想办法使用动规
    // dp[i][j] = max(dp[i-1][j], dp[i][j-1])+1 ， 额，后来发现这个是用来求走到右下角的步数的。 但是后来发觉之前做过类似的，但是又不是，因为如果是从左上角到右下角的步数是确定的

    // 注意：这个不是来求得走的步数的， 而是求路径总和
    // 那么 初始化条件基本上可以确定第一行和第一列必定是路径总和数为1
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n,0));

        for(int i = 0;i<m;++i)
        {
            dp[i][0] = 1;
        }
        for(int j = 0;j < n;++j)
        {
            dp[0][j] = 1;
        }
        for(int i = 1;i<m;++i)
        {
            for(int j = 1;j<n;++j)
            {
                dp[i][j] = dp[i][j-1] + dp[i-1][j]; 
            }
        }
        return dp[m-1][n-1];
    }
};

// 组合数学 ，想不出来

// 要到达右下角， 那么就要走m+m-2步，m-1次向下移动，n-1次向右移动
// 所以路劲的总和就是 再m+n-2次中选择m-1次向下移动的方案数， 这就是组合问题

// (m+n-2)(m+n-3)(m+n-4) ... (n) / (m-1)!

// 组合数学
class SolutionV1
{
public:
    int uniquePaths(int m, int n) {
        int n_ = n;
        int ans = 1;
        for(int m_ = 1;m_ < m;++m_,++n_)
        {
            ans = (ans * n_) / m_;  
        }
        return ans;
    }
};
int main()
{
    SolutionV1 sl;
    cout << sl.uniquePaths(3,7);
    
}