// 72 编辑距离
// 计算出将 word1 转换成 word2 所使用的最少操作数 。
// word1和word2都可以被操作
#include <string>
#include <iostream>
#include <vector>
using  namespace std;
class recursionSolution {
public:
//递归法
    int minDistance(string word1, string word2) {
        if(word1.length() == 0 || word2.length() == 0){
            return max(word1.length(), word2.length());
        }

        if(word1.back() == word2.back()){
            return  minDistance(word1.substr(0, word1.length()-1), word2.substr(0, word2.length()-1));
        }

        return 1+min(
        min(minDistance(word1, word2.substr(0, word1.length()-1)), 
        minDistance(word1.substr(0, word1.length()-1), word2)), 
        minDistance(word1.substr(0, word1.length()-1), word2.substr(0, word2.length()-1))
        );
        // but it will cause stack overflow
    }
};

// word1 abce
// word2 abcd
//思考每个步骤，要继续比较是比较哪些段的字符串
// add operation word1 + d, then compare word1 and word2.substr(0,len-1), samely word2 and word1.substr(len - 1)

// delete operation word1 - e, then compate word1.substr(0, len-1) and word2, this is same with add operation

// so swap operaion is overwrite word1's "e" to word2's "b", so compare word1.substr(0, len-1)  and word2.substr(0, len-1)


//pass by dp， we can memorize the result， and it will descrease the O（n） of algorithm

// create a dp matrix， if word1[i] == word2[j] , op[i][j] = op[i-1][j-1]
//                      else op[i][j] = min(op[i-1],op[j-1], op[i][j-1], op[i-1][j])
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length(), m = word2.length();
        if(n == 0 || m == 0 ){
            return  max(n, m);
        }

        vector<vector<int> > dp;
        for(int i = 0;i<n+1;i++){
            vector<int> row;
            for(int j = 0;j < m+1;j++){
                if(i == 0){
                    row.push_back(j);
                }
                else if(j == 0){
                    row.push_back(i);
                }
                else{
                    row.push_back(0);
                }
                dp.push_back(row);
            }
        }



    }
};
int main(){
    string s1 = "abcd", s2 = "abcdeee";
    Solution sl;
    cout << sl.minDistance(s1, s2) << endl;
}