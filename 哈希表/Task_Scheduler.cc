/*
 * @Date: 2021-11-05 20:17:43
 * @LastEditors: kafier
 * @LastEditTime: 2021-11-06 11:08:55
 * @FilePath: /leetcodeex/哈希表/Task_Scheduler.cc
 */

#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <limits.h>
#include <numeric>          // accumulate in this file
using namespace std;
/**
 * @description: 
 *  避免相同种类的任务， 避免进入待命状态， 那么先执行不一样的不就ok
 *  用一个哈希表记录对应的频率
 *  而后根据n先把不同的给分配了, 如果执行完就回到原先的任务
 *  
 * 贪心策略， 将不处于冷却时间并且剩余次数最多的任务给执行了， 那么不如做一个二元组试试看
 * @param { tasks, n }
 * @return {*}
 * @bug  总体思路是一致的， 就是在erase那个位置出了bug, 对于最后一个元素erase的过早， 导致不一致的问题
 */
class Solution {
public:

    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, pair<int, int>> time_fre;
        // 初始化条件， pair<time, the frequency last>  @param time指的是待命状态后第一个能够执行的时间片， @param  the frequency last 是还剩下多少个任务没有执行
        for(auto& ch : tasks){
            time_fre[ch].first = 1;
            time_fre[ch].second += 1; 
        }

        // 根据能够第一个执行的时间片排序而后再对剩余的数量排序, 但是这么做得每次都排序实在是太麻烦
        // 把i当作时间片
        int ans = 0;
        for(int i = 1; i <= 100; ++i){
            pair<char, pair<int, int>> maxElem;
            maxElem.second.second = 0;      // 先将对应的任务数设置好
            for(const auto& task: time_fre){
                if(task.second.second == 1){
                    time_fre.erase(task.first);
                }                
                else if(task.second.first <=  i){// 如果存在匹配的时间片, 将之保存起来， 并且找到剩余任务最多的任务， 将他执行（剪掉一个任务）
                    if(task.second.second > maxElem.second.second){
                        // maxElem.second.second = task.second.second;
                        maxElem.first = task.first;
                        maxElem.second = task.second;
                    }
                    // 找到最大的之后， 将对应的任务数减少  ———————— 跳到循环外去
                }

            }
            if(maxElem.second.second != 0){
                //有匹配的数
                time_fre[maxElem.first] = make_pair(i + n + 1, maxElem.second.second - 1);
            }// 对于其他没有匹配的数 （ 不处于冷冻时间内的） 必须给他加个时间片， 或者直接加个小于的判断
            if(time_fre.empty()){
                // 如果为空， 那么就说明全部执行完了
                ans = i;
                break;
            }
        }
        
        return ans;
    }
};

// 模拟法
/**
 * @description: 
 *  花了那么时间写出的垃圾代码， 来计算时间复杂度 O(|task| * m ) 
 *  空间复杂度为 O (m)
 * @param {*}
 * @return {*}
 */

class Solution1 {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;
        for (char ch: tasks) {
            ++freq[ch];
        }
        
        // 任务总数
        int m = freq.size();
        vector<int> nextValid, rest; // 类似的是 他使用两个数组来存储
        for (auto [_, v]: freq) {
            nextValid.push_back(1);
            rest.push_back(v);
        }

        int time = 0;
        for (int i = 0; i < tasks.size(); ++i) {
            ++time;
            int minNextValid = INT_MAX;
            for (int j = 0; j < m; ++j) {
                if (rest[j]) {  // 这里是找到最小时间的task
                    minNextValid = min(minNextValid, nextValid[j]);
                }
            }
            // 同时更新 time 时间片，如果在time 这个时间片中有能够执行的task， 那么就对best索引的两个数组进行更改
            time = max(time, minNextValid);
            int best = -1;
            for (int j = 0; j < m; ++j) {
                if (rest[j] && nextValid[j] <= time) {
                    if (best == -1 || rest[j] > rest[best]) {
                        best = j;
                    }
                }
            }
            nextValid[best] = time + n + 1;
            --rest[best];
        }

        return time;
    }
};

// 
/**
 * @description: 
 * 使用一个矩阵来完成这个题目
 * 矩阵的行数是任务的种类数， 列数是n ,也算是时间片
 * 把任务种类中执行次数最多的一种， 记为A， 执行次数为maxEexc， 由于冷却时间为n， 因此将所有的A排布在矩阵的第一列， 所以对应的最小总时间为(maxExec - 1) (n + 1) + 1 
 * 接下来就是在最终的maxExec这里会有所不同， 我们假设在第maxExec次， 要执行的任务数量为maxCount ， 那么总时间为 (maxExec - 1)(n + 1) + maxCount
 * 这边假设一定有 maxCount <= n + 1 才会符合上述公式
 * 
 * 如果maxCont > n+1 那么待命时间就可以忽略掉了， 总执行时间就任务的总数 |task| 
 * @param {*}
 * @return {*}
 */

class Solution2{
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;
        for(auto& ch: tasks){
            ++freq[ch];
        }
        // 找出拥有最大执行次数的任务 -> second 就最多执行任务次数
        int maxExec = max_element(freq.begin(), freq.end(), [](const auto& u, const auto& v){
            return u.second < v.second;
        })->second;
        // 能够到达最大执行任务次数的任务数量， （到达最大一行的任务数量）
        int maxCount = accumulate(freq.begin(), freq.end(), 0, [=](int acc, const auto& u){
            return acc + (u.second == maxExec);
        });

        return max((maxExec - 1) * (n + 1) + maxCount, static_cast<int> (tasks.size()));
    }
};


int main(){
    vector<char> task = {'A','A','A','B','B','B'};
    Solution sl;
    cout << sl.leastInterval(task, 2) << endl;
    // cout << sl.sss << endl;
}

/**
 * @description: 重新回忆匿名函数
 *  []        //未定义变量.试图在Lambda内使用任何外部变量都是错误的.
    [x, &y]   //x 按值捕获, y 按引用捕获.
    [&]       //用到的任何外部变量都隐式按引用捕获
    [=]       //用到的任何外部变量都隐式按值捕获
    [&, x]    //x显式地按值捕获. 其它变量按引用捕获
    [=, &z]   //z按引用捕获. 其它变量按值捕获
 */
