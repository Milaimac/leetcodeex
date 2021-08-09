#include<stack>
#include<string>
#include<deque>
#include<iostream>
using namespace std;
class Solution {
public:
//没有括号的数字没保留下来
    string reverseParentheses(string s) {
        stack<char> symbalstk;
        string res;
        deque<char> svec;
        int flag = 0;
        for(int i=0;i<s.length();i++){
            if(s[i] == '('){
                symbalstk.push('(');
                flag += 1;
            }
            else if(s[i] == ')'){
                flag -= 1;
                if(flag != 0){
                    while(symbalstk.top() != '('){
                       svec.push_back(symbalstk.top());
                       symbalstk.pop(); 
                    }
                    symbalstk.pop();    
                    while(svec.size() != 0){
                        symbalstk.push(svec.front());
                        cout << svec.size() << endl;
                        svec.pop_front();  
                    }
                }
                else{
                    while(symbalstk.top() != '('){
                        res.push_back(symbalstk.top());
                        symbalstk.pop();
                    }
                }
            }
            else if(s[i] >= 'a' && s[i] <= 'z' && flag != 0){
                symbalstk.push(s[i]);
            }else if(s[i] >= 'a' && s[i] <= 'z' && flag == 0){
                res.push_back(s[i]);
            }
        }

        return res;

    }
};

int main(){
    Solution sl;
    string s = "a(u(love)i)b";

    string res = sl.reverseParentheses(s);
    cout << res;
}