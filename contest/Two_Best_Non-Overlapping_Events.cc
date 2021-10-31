#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
// 5899. 两个最好的不重叠活动
class Solution {
public:
// 很自然地超时了
    int maxTwoEvents(vector<vector<int>>& events) {
        // 只能有两个活动， 不重叠的
        vector<int> select1 = vector<int>(3);
        int len  = events.size();   
        int maxres = 0;
        for(int i = 0;i< len;++i){
            select1[0] = events[i][0], select1[1] = events[i][1], select1[2] = events[i][2];
            for(int j = 0;j < len;j++){
                // 要求不重叠
                if(select1[0] > events[j][1]  || select1[1] < events[j][0]){
                    int sum = select1[2] + events[j][32];
                    maxres = max(sum, maxres);
                }
                else if(select1[0] == events[j][0] && select1[1] == events[j][1]){
                    maxres = max(maxres, select1[2]);
                }
            }
        }
        return maxres;
    }
};
// 使用优先队列 将结束时间给存到优先队列， 而后和遍历地开始时间比较
// 这里一个比较秒的地方就是， 它通过加入将最小的结束时间加入了之后，hi就更新为对应的值， 虽然后面出栈了，但是接下来的元素即便入栈， 也没法达到pq.top().first < start 的要求， 那么hi就没有被更新， 所以以hi为结束时间的可以继续叠加

// 于此同时，hi的意义是对于现在再遍历的数而言， 是最优(价值最大)的叠加对象 hi = max(hi, pq.top().second)
class Solution1 {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end()); /* 按照start时间从小到大排序 */
        priority_queue<pair<int, int> ,vector<pair<int, int>>, greater<>> pq;
        int ans = 0;
        int hi  = 0;

        for (int i = 0; i < events.size(); i++) {
            int start = events[i][0];
            int end   = events[i][1];
            int value = events[i][2];
            /* 当最小的结束时间小于开始时间, 更新最小的结束时间,  也就是可以叠加了
               并更新已经弹出的最大值 */
            while (!pq.empty() && pq.top().first < start) {
                hi = max(hi, pq.top().second);
                pq.pop();
            }
            ans = max(ans, hi + value);
            pq.emplace(end, value); /* 将结束时间, 价值加入优先队列 */
        }
        return ans;
    }
};


int main()
{
    vector<vector<int>> vc = {{1,3,2},{4,5,1},{6,7,3}};
    Solution1 sl;
    cout << sl.maxTwoEvents(vc);

}