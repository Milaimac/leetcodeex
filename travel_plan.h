#include<iostream>
#include<string>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;
const int MAXV = 510;
const int INF = INT_MAX;


class travel_plan{
    int n,m,st,ed,G[MAXV][MAXV],cost[MAXV][MAXV];
    int d[MAXV], c[MAXV], pre[MAXV];
    bool vis[MAXV] = {false};

    void Dijkstra(int s){
        fill(d, d+MAXV, INF);
        fill(c, c+MAXV, INF);
        for(int i=0;i<n;i++){
            pre[i] = i;
        }
        d[s] = 0;
        c[s] = 0;
        for(int i=0;i<n;i++){
            int u =-1, MIN = INF;
            for(int j=0;j<n;j++){
                if(vis[j] == false && d[j] < MIN){
                    u = j;
                    MIN = d[j];
                }
            }
            if(u == -1){
                return ;
            }

            vis[u] = true;
            for(int v=0;v<n;v++){
                if(vis[v] == false && G[u][v] != INF){
                    if(d[u] + G[u][v] < d[v]){
                        d[v] = d[u] + G[u][v];
                        c[v] = c[u] + cost[u][v];
                        pre[v] = u;
                    }
                    else if(d[u] + G[u][v] == d[v]){
                        if(c[u] + cost[u][v] < c[v]){
                            c[v] = c[u] + cost[u][v];
                            pre[v] = u; 
                        }
                    }
                }
            }
        }
    }
    void DFS(int v){
        if(v == st){
            cout << v << " ";
            return;
        }
        DFS(pre[v]);
        cout << v << " ";
    }
    void test(){
        cin >> n >> m >> st >> ed;
        int u,v;
        fill(G[0], G[0]+MAXV*MAXV, INF);
        for(int i=0;i<m;i++){
            cin >> u >> v;
            cin >> G[u][v] >> cost[u][v] ;
            G[v][u] = G[u][v];
            cost[v][u] = cost[u][v];
        }
        Dijkstra(st);
        DFS(ed);
        cout << d[ed] << c[ed] << endl;
        
    }
};




















class travel_plan1{
    int n,m,st,ed,G[MAXV][MAXV],cost[MAXV][MAXV];
    int d[MAXV],mincost = INF;
    bool vis[MAXV] = {false};
    vector<int> pre[MAXV];       // 前躯,
    vector<int> tempath, path;  //临时路径、最优路径

    void Dijkstra(int s){
        fill(d, d+MAXV, INF);
        // fill(c, c+MAXV, INF);
        for(int i=0;i<n;i++){
            int u =-1, MIN = INF;
            for(int j = 0;j <=n;j++){
                if(vis[j] == false && d[j] < MIN){
                    u = j;
                    MIN = d[j];
                }
            }
            if(u == -1) return;
            vis[u] = true;
            for(int v=0;v<n;v++){
                if(vis[u] == false&&G[u][v] != INF){
                    if(d[u] + G[u][v] <  d[v]){
                        d[v] = d[u] + G[u][v];
                        pre[v].clear();
                        pre[v].push_back(u);
                    }else if(d[u] + G[u][v] == d[v]){
                        pre[v].push_back(u);
                    }
                }
            }
        }           
    }
    void DFS(int v){
        if(v == st){
            tempath.push_back(v);
            int tempcost  =0;
            for(int i = tempath.size()-1;i>0;i--){
                int id = tempath[i], idNext = tempath[i-1];
                tempcost += cost[id][idNext];
            }
            if(tempcost < mincost){
                mincost = tempcost;
                path = tempath;

            }
            tempath.pop_back();
            return;
        }
        tempath.push_back(v);
        for(int i = 0;i < pre[v].size(); i++){
            DFS(pre[v][i]);

        }
        tempath.pop_back();
    }
    void test(){
        cin >> n >> m >> st >> ed;
        int u,v;
        fill(G[0], G[0]+MAXV*MAXV, INF);
        for(int i=0;i<m;i++){
            cin >> u >> v;
            cin >> G[u][v] >> cost[u][v] ;
            G[v][u] = G[u][v];
            cost[v][u] = cost[u][v];
        }
        Dijkstra(st);
        DFS(ed);
        for(int i = path.size()-1;i>=0;i--){
            cout << path[i];
        }
        cout << d[ed]<<" " << mincost << endl;
    
        
    }

};