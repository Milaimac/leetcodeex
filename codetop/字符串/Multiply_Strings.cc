/*
 * @Date: 2021-12-02 08:47:41
 * @LastEditors: kafier
 * @LastEditTime: 2021-12-02 09:27:14
 */

#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    /**
     * @description:
     * 用模拟法解决。 从后到前面遍历 
     * @param {string} num1
     * @param {string} num2
     * @return {*}
     */
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0"){
            return "0";
        }
        

        int m = num1.size(), n = num2.size();
        // 直接用ansArr存储对应的数字， 到后面在将进位弄上
        vector<int> ansArr(m+n);
        for(int i = m-1;i >= 0;--i){
            int x = num1.at(i) - '0';
            for(int j = n-1;j >= 0;--j){
                int y = num2.at(j) - '0';
                ansArr[i+j+1] += x*y;
            }
        }

        for(int i = m+n-1;i>0;--i){
            ansArr[i-1] = ansArr[i]/10;
            ansArr[i] %= 10;
        }

        int index = ansArr[0] == 0 ? 1 : 0;
        string ans;
        while(index < m+n){
            ans.push_back(ansArr[index]);
            ++index;
        }

        for(auto& c:ans){
            c+='0';
        }
        return ans;
    }

    
};