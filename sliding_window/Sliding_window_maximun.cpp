#include <vector>
#include <unordered_map>
#include <queue>
#include <iostream>
using namespace std;
//滑动窗口最大值 239
class pqSolution{
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k){
        int n = nums.size();
        priority_queue<pair<int, int>> q;       //之所以使用 pair是为了记录位置，以便更好地在优先队列删除

        for(int i=0;i<k;i++){
            q.emplace(nums[i], i);
        }

        vector<int> res = {q.top().first};

        for(int i = k;i<n;++i){
            q.emplace(nums[i], i);
            while (q.top().second <= i-k)
            {
                q.pop();
            }

            res.push_back(q.top().first);
            
        }
        return res;
    }
};


class Solution{
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k){
        int n = nums.size();
        deque<int> q;
        for(int i=0;i<k;i++){
            while(!q.empty() && nums[i] >= nums[q.back()]){
                q.pop_back();
            }
            q.push_back(i);
        } 

        vector<int> ans = {nums[q.back()]};
        for(int i = k;i<n;i++){
            while(!q.empty() && nums[i] >= nums[q.back()]){
                q.pop_back();
            }

            q.push_back(i);
            if(q.front() <= i-k){
                q.pop_front();
            }
            ans.push_back(q.back());
        }
        return ans;
    }
};

