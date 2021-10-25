#include <iostream>
#include <set>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
// 49. 字母异位词分组
class Solution {
public:

    // n 是strs字符串的数量， k是strs中最长字符串的长度， 
    // O(n  klog(k))  遍历strs的时间复杂度和排序str的时间复杂度

    // 空间复杂度O(nk)
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // 额。 strs的长度可以到达10^4, 哈希表作废
        // 欸， 不对， 如果说只是重复的多呢？
        // set<string> non_repeatStrs;
        // 不使用set了， 在后续加入很麻烦
        unordered_map<string, vector<string>> non_repeatStrs;
        for(auto &str: strs)
        {
            string temp = str;
            sort(temp.begin(), temp.end());
            // 也不需要管是否在哈希表里面 ， 直接生成便可以
            non_repeatStrs[temp].emplace_back(str);
        }

        for(auto &ele:non_repeatStrs)
        {
            res.push_back(ele.second);
        }
        return res;
    }
    // 不用这种愚蠢的办法来做一个拷贝
    // string mySort(string str)
    // {
    //     sort(str.begin(), str.end());
    //     return str;
    // }


    vector<vector<string>> groupAnagramsv1(vector<string>& strs) {
        
    }
    vector<vector<string>> res;
};

// 工作： 将字母异位词组合到一个数组

