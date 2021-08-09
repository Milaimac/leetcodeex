#include<vector>
#include<algorithm>
using namespace std;
const int MAXV = 1000;
const int INF = 10000000;
   
class Prim{
    int n, G[MAXV][MAXV];
    int d[MAXV];
    bool vis[MAXV] = {false};
    int prim(){
        fill(d, d+MAXV, INF);
        d[0] = 0;
        int ans = 0; //存放最小生成数的边权之和。
        for(int i=0;i<n;i++){
            int u = -1, MIN = INF;
            for(int j = 0;j<n;j++){  //找未访问结点最小的。
                if(vis[j] == false && d[j] < MIN){
                    u = j;
                    MIN = d[j];
                }
            }
            if(u == -1){
                return -1;
            }
            vis[u] = true;
            ans += d[u]; //将与集合s距离最小的边加入最小生成树。

            for(int v=0;v<n;v++){
                if(vis[u] == false && G[u][v] != INF && G[u][v] < d[v]){
                    d[v] = G[u][v];// d[v]表示顶点与集合s的最小距离。
                }
            }
        }
        return ans;
    }   
};


struct Node{
    int v, dis;
};
class Prim1{

    vector<Node> Adj[MAXV];
    int n;
    int d[MAXV];
    bool vis[MAXV] = {false};
    int prim(){
        fill(d, d+MAXV, INF);
        d[0] = 0;
        int ans = 0;
        for(int i=0;i<n;i++){
            int u =-1, MIN = INF;
            for(int j = 0;j<n;j++){
                if(vis[j] == false && d[j] < MIN){
                    u = j;
                    MIN = d[j];
                }
            }
            if(u == -1){
                return -1;
            }
            vis[u] = true;
            ans += d[u];
            for(int j = 0;j < Adj[u].size();j++){
                int v = Adj[u][v].v;
                if(vis[v] == false && Adj[u][j].dis < d[v]){
                    d[v] = Adj[u][j].dis;
                }
            }
        }
        return ans;
    }

};



