/*
 * @Date: 2021-12-02 11:03:51
 * @LastEditors: kafier
 * @LastEditTime: 2021-12-02 11:18:47
 */
#include <string>
using namespace std;
class Solution
{
public:
    /**
     * @description: 
     * 
     * 要忽略前导零， 然后每个.作为分割符， 对version进行比较
     * @param {string} version1
     * @param {string} version2
     * @return {*}
     */
    int compareVersion(string version1, string version2)
    {
        int n = version1.size(), m = version2.size();
        int i = 0, j = 0;
        while (i < n || j < m)
        {
            int x = 0;
            for(;i < n && version1[i] != '.';++i){
                x = x*10 + version1[i]- '0';
            }

            ++i;

            int y = 0;
            for(;j< m && version2[j]!= '.';++j){
                y = y * 10 + version2[j] - '0';
            }
            ++j;

            if(x != y){
                return x > y ? 1 : -1;
            }
        }
        return 0;
    }
};