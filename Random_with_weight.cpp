#include<vector>
#include<random>
#include<iostream>
using namespace std;
// 528. 按权重随机选择
class Solution {
private:
    mt19937 gen;        //用random_device创建随机数
    uniform_int_distribution<int> dis;
    vector<int> pre;
    

public:
    Solution(vector<int>& w) :gen(random_device{}()), dis(1, accumulate(w.begin(), w.end(), 0)){
        partial_sum(w.begin(), w.end(), back_inserter(pre));
    }
    
    int pickIndex() {
        int x = dis(gen);
        return lower_bound(pre.begin(), pre.end(), x) - pre.begin();
    }
};


class ClassicSolution{
public:
    int range = 0;
    vector<int> weights;
    ClassicSolution(vector<int>& w){
        for( auto w_:w){
            weights.push_back(range);
            range += w_;
        }
    }
    int pickIndex(){
        int rnd = rand() % range;
        int i =0;
        for(i = 1;i<weights.size();i++){
            if(rnd < weights[i]){
                break;
            }
        }
        return i-1;
    }
};

class BinarySolution:public ClassicSolution{
public:
// if base class has itself constructor, the derive class must use the base class 's consturctor
    BinarySolution(vector<int>& w):ClassicSolution(w){
    }

    int pickIndex(){
        int rnd  = rand() % range;
        int left = 0;
        int right = weights.size() - 1;
        while(left < right){
            int mid = left + (right - left) /2;
            if(rnd < weights[mid]){
                right = mid;
            }else{
                left = mid + 1;
            }
        }
        return left;
    }
};

int main(){
    vector<int> w = {1,3};
    Solution sl(w);
    for(int i =0;i<12;i++){
        cout << sl.pickIndex() << " ";
    }
    cout << endl; 
}