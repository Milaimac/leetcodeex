/*
 * @Date: 2021-12-02 08:40:21
 * @LastEditors: kafier
 * @LastEditTime: 2021-12-02 08:44:25
 */
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string path = "";
        backtrack(n, path, 0, 0);
        return ret;
    }

    void backtrack(int& n, string& path, int open, int close){
        if(path.size() == 2*n){
            ret.push_back(path);
        }

        if(open < n){
            path.push_back('(');
            backtrack(n, path, open+1,close);
            path.pop_back();
        }

        if(close < open){
            path.push_back(')');
            backtrack(n, path, open, close+1);
            path.pop_back();
        }
    }
    vector<string> ret;
};