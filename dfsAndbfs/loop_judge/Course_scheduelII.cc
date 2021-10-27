#include <vector>
#include <algorithm>
using namespace std;

// 返回你为了学完所有课程所安排的学习顺序。 可能会有多个正确的顺序， 你只要返回 任意一种 就可以了。 如果不可能完成所有课程， 返回一个空数组。

// 将深度优先搜索的流程和拓扑排序的求解联系起来， 用一个栈来存储所有已经搜索完成的节点
// 假如我们当前搜索到了节点u， 如果它的所有相邻节点都已经搜索完成， 那么这些节点都已经在栈中了。 此时我们就可以把u入栈， 如果从栈顶往栈顶的顺序看， 由于u处于栈顶的位置， 那么u出现所有u的相邻节点的前面。 因此对于u这个节点的前面。

// 算法

// 对于图中的任意一个节点，它在搜索的过程中有三种状态，即：

//     「未搜索」：我们还没有搜索到这个节点；

//     「搜索中」：我们搜索过这个节点，但还没有回溯到该节点，即该节点还没有入栈，还有相邻的节点没有搜索完成）；

//     「已完成」：我们搜索过并且回溯过这个节点，即该节点已经入栈，并且所有该节点的相邻节点都出现在栈的更底部的位置，满足拓扑排序的要求。

// 通过上述的三种状态，我们就可以给出使用深度优先搜索得到拓扑排序的算法流程，在每一轮的搜索搜索开始时，我们任取一个「未搜索」的节点开始进行深度优先搜索。

//     我们将当前搜索的节点 u  标记为「搜索中」，遍历该节点的每一个相邻节点 v ：

//         如果 v 为「未搜索」，那么我们开始搜索 v ，待搜索完成回溯到 u ；

//         如果 v  为「搜索中」，那么我们就找到了图中的一个环，因此是不存在拓扑排序的；

//         如果 v  为「已完成」，那么说明 v 已经在栈中了，而 u  还不在栈中，因此 u  无论何时入栈都不会影响到 (u, v) 之前的拓扑关系，以及不用进行任何操作。

//     当 u 的所有相邻节点都为「已完成」时，我们将 u  放入栈中，并将其标记为「已完成」。

// 这个就是将入度为0 的节点丢入栈中， 因为出度为0， 就说明没有课程是它的前置课程

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        visited.resize(numCourses);
        for(const auto& info:prerequisites){
            edges[info[1]].push_back(info[0]);  // 这种写法是将info[0] 后置课程作为值,并且以info[1]作为前置课程的课程是一个表， 这是一个邻接表
        }

        for(int i = 0;i < numCourses && valid;++i){
            if(!visited[i]){// 如果没有搜索过的， 就可以dfs
                dfs(i);
            }
        }

        if(!valid){
            return {};
        }
        // 最终反转
        reverse(result.begin(), result.end());
        return result;
    }

    void dfs(int u )
    {   
        // 标记为正在搜索中
        visited[u] = 1;
        // u 的下一个节点（下一个课程）是v， 当一个课程 这个就应该排列上去
        for(int v:edges[u]){
            // 如果相邻节点没有被搜索
            if(visited[v] == 0){
                dfs(v);
                if(!valid){
                    return;
                }
            }
            else if(visited[v] == 1){ // 如果相邻的节点为 搜索中，说明有环
                valid = false;
                return;
            }
        }
        // 将相邻的节点搜索完成 如果说该节点的出度为0, 那么就不会执行循环 （也就是说它是最后一个课程）
        visited[u] = 2;
        result.push_back(u);
    }
private:
    //  存储有向图
    vector<vector<int>> edges;
    // 标记每个节点的状态
    vector<int> visited;
    // 用数组来模拟栈， 下标为0为栈底， n-1为栈顶
    vector<int> result;
    // 判断是否有环
    bool valid = true;
};

int main()
{
    int numcourse = 4; 
    vector<vector<int>> pre = {{1,0},{2,0},{3,1},{3,2}};
    Solution sl;
    sl.findOrder(numcourse, pre);

}