/*
 * @Date: 2021-12-10 18:45:15
 * @LastEditors: kafier
 * @LastEditTime: 2021-12-11 23:00:59
 */
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> edges(numCourses);
        vector<int> indge(numCourses);

        for(const auto& info:prerequisites)
        {
            auto& start = info[1];
            auto& end = info[0];
            edges[start].push_back(end);
            ++indge[end];
        }

        queue<int> q;

        for(int i = 0;i < numCourses;++i)
        {
            if(indge[i] == 0)
            {
                q.push(i);
            }
        }

        int visited = 0;
        while(!q.empty()){
            ++visited;
            int u = q.front();
            q.pop();
            for(int v:edges[u])
            {
                --indge[v];
                if(indge[v] == 0)
                {
                    q.push(v);
                }
            }
        }
        return visited == numCourses;
    }
};