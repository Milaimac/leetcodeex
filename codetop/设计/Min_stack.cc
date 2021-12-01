/*
 * @Date: 2021-11-29 16:27:44
 * @LastEditors: kafier
 * @LastEditTime: 2021-11-30 11:40:51
 */
/**
 * @description:
 * 其中的要求是找常数时间单位内找到最小元素的栈
 * 使用一个辅助栈，其中这个栈只存储比栈顶还小的元素， 
 * @param {*}
 * @return {*}
 */

#include <stack>
#include <limits.h>
#include <algorithm>
using namespace std;
class MinStack
{
    stack<int> x_stack;
    stack<int> min_stack;
public:
    MinStack()
    {
        min_stack.push(INT_MAX);
    }

    void push(int val)
    {
        x_stack.push(val);
        min_stack.push(min(min_stack.top(), val)); // 如果min_stack 的top更小，会再存一次， 因此不用担心， 如果pop的时候， 把最小值给pop没了
    }

    void pop()
    {
        x_stack.pop();
        min_stack.pop();
    }

    int top()
    {
        return x_stack.top();
    }

    int getMin()
    {
    }
};

// 看到评论， 居然还要求不能够使用额外的空间复杂度
/**
 * @description: 
 * 大致有两种方法； 
 * 1. 利用位运算， 利用前16位存储元素， 后16位存储最小值， 这样只利用一个栈， 然后取值的时候通过移位的方法来获取值， 不过这样数值范围就会限制再- 2^15到 2^15-1；
 * 2. 在栈中存放当前元素和最小值的差值， 思路
 * - 创建一个栈， 初始化位0， min变量初始化为va
 * - 入栈： 要压入的元素val - min， 如果差值小于0， 说明当前最小值为val， 把差值压入栈， 并更新min， 否则只压入差值， 不更新min
 * @param {*}
 * @return {*}
 */

class MinStack1
{
public:
    int min;
    double dif;
    stack<double> stk;
    MinStack1(){

    }    
    void push(int val)
    {
        if(stk.empty())
        {
            min = val;
            stk.push(0);
        }
        else{
            dif = (double) val - double(min);
            stk.push(dif);
            min = dif < 0 ? val : min;
        }
    }

    void pop()
    {
        if(stk.top() < 0){
            // 更新最小值， 当前最小值 - 栈上差值 = 原先最小值 《==》 当前最小值 - 原先最小值 = 差值 
            min = min - stk.top(); 
        }
        stk.pop(); // 不用返回值
    }

    int top(){
        return stk.top() > 0 ? min + stk.top() : min;
    }

    int getMin(){
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */