#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits.h>
using namespace std;
//超级丑数 313
// 超级丑数 是一个正整数，并满足其所有质因数都出现在质数数组 primes 中。

// 给你一个整数 n 和一个整数数组 primes ，返回第 n 个 超级丑数 。

// 题目数据保证第 n 个 超级丑数 在 32-bit 带符号整数范围内。

//解法一， 使用堆

// 复杂度分析：为得到第n个丑数要进行n次循环，每次循环要从最小堆取出1个元素，以及向最小对加入最多m个元素，因此每次循环的时间复杂度为O(mlog(mn) + log(mn)) = O(mlog(mn)), 则总复杂度为O(nmlog(mn))

//空间复杂度 O(nm)
class heapSolution{
public:
    int nthSuperUglyNumber(int n, vector<int>& primes){
        unordered_set<long> seen;
        priority_queue<long, vector<long>, greater<long> > heap;

        seen.insert(1);
        heap.push(1);

        int ugly = 0;
        for(int i = 0;i < n;i++){
            long curr = heap.top();
            heap.pop();
            ugly = (int)curr;
            for(int prime:primes){
                long next =  curr * prime;
                if(seen.insert(next).second){
                    heap.push(next);
                }
            }
        }
        return ugly;
    }
};

// 使用动态规划

// 时间复杂度 O(n*2m) 




class dpSolution{
public:
    int nthSuperUglyNumber(int n, vector<int> primes){
        vector<int> dp(n);
        vector<int> index(primes.size(), 0);

        dp[0] = 1;
        for(int i = 1;i<n;i++){
            int temp = INT_MAX;
            for(int j = 0;j<primes.size();j++){
                temp = min(primes[j] * dp[index[j]], temp);
                // dp[i] = temp;
                // if(dp[i] == primes[j]* dp[index[j]])    index[j]++;
            }
            dp[i] = temp;

            for(int k =0;k<primes.size();k++){
                if(dp[i] == primes[k]*dp[index[k]])
                    index[k]++;
            }
        }
        return dp[n-1];
    }
};

// int main(){
//     int primes = 
// }