#include <iostream>
#include <list>
using namespace std;

class Solution{
public:
    int lastRemaining(int n, int m){
        // if(n < 1 || m < 1){
        //     return -1;
        // }
        // int i = 0;
        list<int> numbers;
        for(int i = 0;i < n;++i){
            numbers.push_back(i);
        }

        list<int>::iterator current = numbers.begin();
        while(numbers.size() > 1){
            for(int i = 1;i < m;++i){
                current++;
                if(current == numbers.end()){
                    current = numbers.begin();
                }
            }
            auto next = ++current;
            if(next == numbers.end()){
                next = numbers.begin();
            }
            --current;
            numbers.erase(current);
            current = next;
        }
        return (*current);
    }
};
// leetcode式递归
// 通过比较f(n-1,m)和f(n,m)的答案关系，进行递归
class SolutionV1 {
public:
    int f(int n, int m){
        if(n == 1){
            return 0;
        }
        int x = f(n-1, m);
        return (m+x)%n;
    }
    int lastRemaining(int n, int m) {
        return f(n,m);
    }
};
// 迭代
class SolutionV2 {
public:

    int lastRemaining(int n, int m) {
        // return f(n,m);
        int last = 0;
        for(int i = 2;i <= n;++i){
            last += (last+m)%i;
        }
        return last;
    }
};
int main(){}