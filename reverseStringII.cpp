//541. 反转字符串 II
#include <string>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        // 如何反转， 用栈吗？
        int i = 1;
        stack<char> stk;
        int len = s.length();
        string res = "";
        stk.push(s[0]);
        while(i < len){
            // 0 1 2 3 4 5 /4
            if(i % (2*k) < k){ //前k个
                stk.push(s[i]);
            }
            else{
                while(!stk.empty()){
                    res += stk.top();
                    stk.pop();
                }
                res += s[i];
            }
            i++;
        }
        while (!stk.empty())
        {
            /* code */
            res += stk.top();
            stk.pop();
        }
        
        return res;
    }
};
class reverseSolution {
public:

    template<class Iterator, typename T>
    inline void swap(Iterator first, Iterator last){
        T _tmp = *first;
        *first = *last;
        *last = _tmp;
    }
    template <class Iterator, typename  T>
    inline void reverse(Iterator first, Iterator last){
        while(true){
            if(first == last || first == --last){
                return;
            }else{
                swap<Iterator, T>(first++, last);

            }
        }
    }
    string reverseStr(string s, int k) {
        int n = s.length();
        for (int i = 0; i < n; i += 2 * k) {
            reverse<string::iterator,char>(s.begin() + i, s.begin() + min(i + k, n));
        }
        return s;
    }

};
#ifdef REVERSE

template <class BidirectionalIterator
inline void reverse(BidirectionalIterator first, BidirectionalIterator last){
    __reverse(first, last, iterator_category(first));
}

template <class BidirectionalIterator>
void __reverse(BidirectionalIterator first, BidirectionalIterator last, bidirectional_iterator_tag){
    while(true){
        if(first == last || first == --last){
            return;
        }
        else{
            iter_swap(first++, last);
        }
    }
}
#endif
int main(){
    string s = "abcdefg";
    Solution sl;
    string res = sl.reverseStr(s, 2);
    cout << res << endl;
}