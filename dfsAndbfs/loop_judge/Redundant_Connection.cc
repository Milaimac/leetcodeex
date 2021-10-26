#include <vector>
using namespace std;
//684. 冗余连接

// 要判断是否有没有环， 常规的做法，是将入度为0的节点，一个一个排除掉， 如果最终全部排除， 那么就是无环

// 树是一个连通且无环的图， 在树中多加一条边就会出现环， 所以附加的边， 就是导致环出现的边

// 通过并查集寻找附加的边。 初始时， 每个节点都是与不同的连通分量， 遍历每一条边， 判断这条边连接的两个顶点是否属于相同的连通分量

// 通常来讲， 能够使用并查集解决的， 就能够使用dfs解决， 只不过dfs的复杂度比较高
class Solution {
public:

    int Findfater(vector<int>& parent, int index){
        if(parent[index] != index){
            parent[index] = Findfater(parent, parent[index]);
        }
        return parent[index];
    }
    // 这个合并的操作有些困惑
    // [1] [2] [3] 
    // union 2  [1 , 2] 
    // union 3 [1, 2 ,3] 
    void Union(vector<int>& parent, int index1, int index2){
        parent[Findfater(parent,index1)] = Findfater(parent, index2);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n+1);
        for(int i = 1;i <= n;++i)
        {
            parent[i] = i;
        }

        for(auto& edge:edges){
            int  node1 = edge[0], node2 = edge[1];
            // 通过并查集， 将原来不属于同一并查集的给连接起来， 成为一个集合
            // 如果后来发现有同个集合， 说明连接成环
            // 这里的前提条件，必须是edge是不会重复的
            if(Findfater(parent, node1) != Findfater(parent, node2)){
                Union(parent, node1, node2);
            }else{
                return edge;
            }
        }

        return vector<int> {};
    }
};