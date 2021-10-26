#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    //使用滑动窗口来实现，可以实现到O(N)的复杂度
    // 如果是单纯的遍历， 回到达O(m,n)的复杂度
    // 至于如何判断两个是字符串异位词， 直接通过26字母的哈希表， 记录其中的频次来解决
    // 通过这个方法将 O(mn) 变成了 O(26n)
    vector<int> findAnagrams(string s, string p) {
        int n = s.length();
        int m = p.length();

        vector<int> ret;
        vector<int> pCnt(26), sCnt(26);
        if(n < m)   return ret;
        for(int i = 0;i < m;++i)
        {
            pCnt[p[i]-'a']++;
            sCnt[s[i]-'a']++;
        }
        // 但是要怎么直接比较频次呢？
        if(equal(pCnt, sCnt)){
            ret.push_back(0); 
        }
        // 接下来就是滑动窗口了
        for(int i = m;i < n;++i)
        {
            sCnt[s[i-m]-'a']--;
            sCnt[s[i]-'a']++;
            if(equal(pCnt, sCnt)){
                ret.push_back(i-m+1);
            }
        }

        return ret;
    }

    bool equal(vector<int> &arr1, vector<int>& arr2)
    {
        // 不用判断长度是否相等了
        int n = arr1.size();
        for(int i = 0;i<n;++i)
        {
            if(arr1[i] != arr2[i])
            {
                return false;
            }
        }
        return true;
    }
};