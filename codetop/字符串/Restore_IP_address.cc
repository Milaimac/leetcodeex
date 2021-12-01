/*
 * @Date: 2021-11-17 23:42:17
 * @LastEditors: kafier
 * @LastEditTime: 2021-11-18 23:51:40
 */

#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    /**
     * @description: 
     * IP地址的每个整数位于0 到 255之间， 整数之间用 '.'来分隔。 
     * 对于一个字符串， 有多种复原方式。 
     * @param {string} s
     * @return {*}
     */
    vector<string> restoreIpAddresses(string s)
    {
        segments.resize(SEG_COUNT);
        dfs(s, 0, 0);
        return ans;
    }

    void dfs(const string &s, int segId, int segStart)
    {
        if(segId == SEG_COUNT){
            // 如果 找完了4段IP地址， 并且遍历完了字符串， 那么就是一种答案
            if(segStart == s.size())
            {
                string ipAddr;
                for(int i = 0;i < SEG_COUNT;++i)
                {
                    ipAddr += to_string(segments[i]);
                    if(i != SEG_COUNT - 1){
                        ipAddr += ".";
                    }
                }
                ans.push_back(move(ipAddr));
            }
            return;
        }
        // 如果没有找到4段IP地址， 就已经遍历完了字符串， 那么提前回溯
        // 没有必要创建超过segId的， 因为如果segId == seg_count && segstart == s.size() ,那么会直接return 
        if(segStart == s.size()){
            return;
        }
        // 特殊清空， 如果遇到s[segStart] == '0'， 那么就直接递归下一个IP地址段。
        if(s[segStart] == '0')
        {
            segments[segId] = 0;
            dfs(s, segId + 1, segStart + 1);
        }

        int addr = 0;
        for(int segEnd = segStart; segEnd < s.size(); ++ segEnd)
        {
            addr = addr * 10 + (s[segEnd] - '0');
            if(addr > 0 && addr <= 0xFF){ // 0xFF = 15 + 15 * 16 == 255 ， 从小的开始
                segments[segId] = addr;
                dfs(s, segId + 1, segEnd +1);
            }
            else
            {
                break;
            }
        }
    }

private:
    static constexpr int SEG_COUNT = 4;

private:
    vector<string> ans;
    vector<int> segments;
};