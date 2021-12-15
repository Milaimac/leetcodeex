/*
 * @Date: 2021-12-04 23:38:34
 * @LastEditors: kafier
 * @LastEditTime: 2021-12-04 23:38:43
 */
#include <stack>
using namespace std;
class CQueue {
public:
    CQueue() {

    }
    
    void appendTail(int value) {
        inputstk.push(value);   
    }
    
    int deleteHead() {
        if(outputstk.empty()){
            while(!inputstk.empty()){
                outputstk.push(inputstk.top());
                inputstk.pop();
            }
        }
        if(outputstk.empty()){
            return -1;
        }
        int ret = outputstk.top();
        outputstk.pop();
        return ret;
    }
private:
    stack<int> inputstk;
    stack<int> outputstk;

};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */