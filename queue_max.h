#include<queue>
#include<deque>
using namespace std;
class MaxQueue {
public:
    MaxQueue() {

    }
    deque<int> q;
    queue<int> axq;
    int max_value() {
        if(q.empty()){
            return -1;
        }
        return axq.front();
    }
    
    void push_back(int value) {
        q.push_back(value);
        while(!axq.empty() && axq.back() < value){
            //如果小于value，将小于value的全部弹出
            
            axq.pop();
        }
        //如果小于，也会直接push到前面front，导致此程序错误。
        axq.push(value);
    }
    
    int pop_front() {
        if(q.empty()){
            return -1;
        }
        if(q.front() == axq.front()){
            axq.pop();
        }
        int res = q.front();
        q.pop_front();
        return res;
    }
};