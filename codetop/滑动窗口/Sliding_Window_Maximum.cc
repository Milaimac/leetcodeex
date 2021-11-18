/*
 * @Date: 2021-11-12 11:31:43
 * @LastEditors: kafier
 * @LastEditTime: 2021-11-18 10:00:06
 * @FilePath: /leetcodeex/codetop/滑动窗口/Sliding_Window_Maximum.cc
 */
#include <vector>
#include <queue>
using namespace std;
class Solution
{
public:
    /**
     * @description:    
     * 两种方法， 
     * 1、使用优先队列， 存储对应的最大值和坐标， 而后只要最大的这个值拿出来用的时候， 判断是否是在滑动窗口内， 如果在，就放到答案数组， 否则pop， 找到下一个最大值。 
     * 2、 使用双端队列， 来模拟这个滑动窗口， 如果添加的新边界大于队列中的值。 那么将小于边界的全部弹出。 如果发现超过滑动窗口的边界fornt， 也要弹出。
     *
     * @param {int} k
     * @return {*}
     */
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {

        priority_queue<pair<int, int>> pq;
        int n = nums.size();
        // res.reserve();        
        vector<int> res(n-k+1);
        for (int i = 0; i < k; ++i)
        {
            pq.push(make_pair(nums[i], i));
            res[0] = pq.top().first;
        }
        int index = 1;
        for (int i = k; i < n;++i){
            pq.emplace(nums[i], i);
            while (pq.top().second <= i-k)          // pop 是将顶给pop掉， 没必要每次都得i-k 给删除掉的， 只要顶端不符合要求 pop掉就ok了
            {
                pq.pop();
            }
            res[index] = pq.top().first;
            ++index;
        }
        return  res;
    }

    vector<int> maxSlidingWindow1(vector<int>&  nums, int k){
        deque<int> q;
        int n = nums.size();
        vector<int> ret;
        for(int i = 0;i < k;++i){
            while(nums[i] > nums[q.back()]){
                q.pop_back();
            }
            q.push_back(i);
        }
        ret.push_back(nums[q.front()]);
        for(int i = k;i < n;++i){
            while(nums[i] > nums[q.back()]){
                q.pop_back();
            }
            q.push_back(i);
            while(q.front() <= i-k){
                q.pop_front();
            }

            ret.push_back(nums[q.front()]);

        
        }
        return ret;
    }
};


int main(){
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    Solution sl;
    sl.maxSlidingWindow(nums, 3);
}