//22. 括号生成
#include <vector>
#include <string>
using namespace std;

// 暴搜递归
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current;
        generate_all(current, n*2, result);
        return result;
    }

    bool valid(const string& str)
    {
        int balance = 0;
        for(const char& c:str)
        {
            if(c == '(')
            {
                ++balance;
            }
            else
            {
                --balance;
            }
            if(balance < 0)
            {
                return false;
            }
        }

        return balance == 0;
    }

    void generate_all(string& current, int n, vector<string>& result)
    {
        if(n == current.size())
        {
            if(valid(current))
            {
                result.push_back(current);
            }
            return;
        }

        current  += '(';
        generate_all(current, n, result);
        current.pop_back();
        current += ')';
        generate_all(current, n, result);
        current.pop_back();
    }

};

// 同理， 利用卡特兰数可以计算其时间复杂度
// 其实我也不知道卡特兰数是什么鬼东西， 但是这个括号匹配有个性质，就是如果右括号大于左括号的话， 那么就可以把它剪掉

// 当left < n的时候， 就i加入左括号， 左括号的加入没有限制
// 当left > right的时候才能够加入右括号
class SolutionV1 {
public:
    vector<string> generateParenthesis(int n) {
        string str = "";
        backtrack(0, 0, str, n);
        return res;
    }

    void backtrack(int left, int right, string str, int n)
    {
        if(str.size() == 2*n)
        {
            res.push_back(str);
            return; 
        }
        if(left < n)
        {
            //加入左括号
            str += "(";
            backtrack(left+1, right, str, n);
            str.pop_back();
        }

        if(left > right)
        {
            str += ")";
            backtrack(left, right+1, str, n);
            str.pop_back();
        }

    }

    vector<string> res;

};