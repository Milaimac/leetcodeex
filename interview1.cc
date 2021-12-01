/*
 * @Date: 2021-11-21 11:14:12
 * @LastEditors: kafier
 * @LastEditTime: 2021-11-21 11:19:13
 */
#include <stack>
#include <iostream>
using namespace std;

class solution{
public:
// 队列 先进先出， 栈 先进后出， 两个栈 ， 一个栈
    solution(){
    }
    void push(int ele){
        intputstk.push(ele);
    }

    int pop(){
        while(!intputstk.empty()){
            outputstack.push(intputstk.top());
            intputstk.pop();
        }
        int ret = outputstack.top();
        outputstack.pop();
        return ret;
    }

    
private:
    stack<int> intputstk, outputstack;

};

int main(){
    solution sl;
    sl
}