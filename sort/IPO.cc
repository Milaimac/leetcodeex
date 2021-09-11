#include<vector>
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
// 502. IPO

typedef pair<int,int> pii;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        int curr = 0;
        priority_queue<int, vector<int>, less<int>> pq;
        vector<pii> arr;

        for (int i = 0; i < n; ++i) {
            arr.push_back({capital[i], profits[i]});
        }
        //sort 是根据arr.firt来排序的
        sort(arr.begin(), arr.end());
        for (int i = 0; i < k; ++i) {
            while (curr < n && arr[curr].first <= w) {
                pq.push(arr[curr].second);
                curr++;
            }
            if (!pq.empty()) {
                w += pq.top();
                pq.pop();
            } else {
                break;
            }
        }

        return w;
    }
};


int main(){
    vector<int> profit = {1,2,3};
    vector<int> captital = {1,0, 1};
    int k = 2;
    int w = 0;
    Solution sl;
    cout <<  sl.findMaximizedCapital(k,w,profit, captital) << endl;

}