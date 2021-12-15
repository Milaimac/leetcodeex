/*
 * @Date: 2021-12-08 14:13:55
 * @LastEditors: kafier
 * @LastEditTime: 2021-12-11 13:24:51
 */

#include <queue>
#include <vector>
using namespace std;

/**
 * @description: 
 * 利用有向图构建邻接表和每个节点的入度。 
 * 而后将入度为0的入队， 根据邻接表将每个入度为0的节点的终点入队， 并且将入度为0的节点放入答案数组中， 或者删除掉。 
 * 
 * @param {int} n
 * @param {vector<vector<int>>} &prerequisites
 * @return {*}
 */
 #include<memory>
 #include <boost/smart_ptr.hpp>
// shared_ptr<int> a = ;
vector<int> haveCircularDependency(int n, vector<vector<int>> &prerequisites)
{
    vector<vector<int>> gird(n);        //邻接表存储图结构
    vector<int> indeg(n);               // 每个点的入度
    vector<int> res;

    for(int i =0;i <prerequisites.size();++i)
    {
        int start = prerequisites[i][0], end = prerequisites[i][1];
        gird[start].push_back(end);
        indeg[end]++;
    }

    queue<int> q;

    // 一次性将入度为0的点全部入队
    for(int i = 0;i < n;++i)
    {
        if(indeg[i] == 0) 
            q.push(i);
    }

    while(q.size())
    {
        int t = q.front();
        q.pop();
        res.push_back(t);

        // 删除边时， 将终点入度 -1， 如果入度为0， 再次将它入队
        for(int i =0;i< gird[t].size();++i)
        {
            int j = gird[t][i];
            indeg[j] --;
            if(indeg[j] == 0)
            {
                q.push(j);
            }
        }
    }
    if(res.size() == n)
        return res;
    // 没有将所有节点加入res， 说明
    else return {};
}