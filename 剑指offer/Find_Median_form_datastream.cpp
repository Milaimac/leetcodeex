// 295. 数据流的中位数
#include<vector>
#include<queue>
using namespace std;    

class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int, vector<int>, less<int>> queMin;
    priority_queue<int, vector<int>, greater<int>> queMax;

    
    MedianFinder() {

    }
    
    void addNum(int num) {
        if(queMin.empty() || num <= queMin.top()){
            queMin.push(num);
            if(queMax.size()+1 < queMin.size()){
                queMax.push(queMin.top());
                queMin.pop();
            }
        }
        else{
            queMax.push(num);
            if(queMin.size() < queMax.size()){\
                queMin.push(queMax.top());
                queMax.pop();
            }
        }
    }
    
    double findMedian() {
        if(queMax.size() < queMin.size()){
            return queMin.top();
        }
        return (queMax.top() + queMin.top())/2.0;
    }
// private:
    

};

//优先队列是基于堆的，那么
template<typename T> class DynamicArray{
public:
    void Insert(T num)
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */