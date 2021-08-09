#include<iostream>
#include<string>
#include<algorithm>
#include<bits/stdc++.h>
#include<set>
using namespace std;
// Emergency
const int MAXV = 510;
const int INF = INT_MAX;

class Emergency{
    int n,m,st,ed,G[MAXV][MAXV], weight[MAXV]; //weight 点权, n是顶点数，m为变数，st和end是起点和终点。
    int d[MAXV], w[MAXV], num[MAXV]; //w点权之和，num记录最短路径数
    bool vis[MAXV] = {false};
    vector<int> pre[MAXV];

public:
    void Dijkstra_1(int s){
        fill(d, d+MAXV, INF);
        d[s] = 0;
        for(int i=0;i<n;i++){
            int u = -1,MIN = INF;
            for(int j =0;j<n;j++){
                if(vis[j] == false && d[j] < MIN){
                    u = j;
                    MIN = d[j];
                }
            }
            if(u == -1) return ;
            vis[u] = true;
            for(int v=0;v<n;v++){
                if(vis[v] == false && G[u][v] != INF){
                    if(d[u] + G[u][v] < d[v]){
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
    void Dijkstra(int s){
        fill(d, d+MAXV, INF);
        memset(num, 0, sizeof(num));
        memset(w,0,sizeof(w));
        d[s] = 0;
        w[s] = weight[s];
        num[s] = 1;
        for(int i=0;i<n;i++){       //对n个结点进行遍历
            int u = -1, MIN = INF;  //u来表示是否连通
            for(int j=0;j<n;j++){   //遍历n个结点，去寻找没有遍历过且是连通的，一开始d[J] = MIN = INT_MAX，除了s。然后第二次遍历时，会去找到距离s最近的结点从而在下个循环去更新d[u]
                if(vis[j] == false && d[j] < MIN){
                    u = j;
                    MIN = d[j];
                }
            }
            if(u == -1){
                return ;
            }
            vis[u] = true;
            for(int v=0;v<n;v++){   //遍历v，去跟新d[v]
                if(vis[v] == false && G[u][v] != INF){
                    if(d[u] + G[u][v] < d[v]){
                        d[v] = d[u] + G[u][v];
                        w[v] = w[u] + weight[v];
                        num[v] = num[u];
                    }
                    else if(d[u]+G[u][v] == d[v]){
                        if(w[u] + weight[v] > w[v]){
                            w[v] = w[u] + weight[v];
                        }
                        num[v] += num[u];
                    }
                }
            }
        }
    }

    void test(){
        cin >> n >> m >> st;
        for(int i =0;i<n;i++){
            cin >> weight[i];
        }
        int u,v;
        fill(G[0], G[0]+MAXV*MAXV, INF);
        for(int i =0;i<m;i++){
            cin >> u >> v;
            cin >> G[u][v];
            G[v][u] = G[u][v];
        }
        Dijkstra(st);
        cout << num[ed] << w[ed] << endl;
    }
};



struct Node{
    int v, dis;
    Node(int _v, int _dis):v(_v), dis(_dis) {};

};

class solusion{
    vector<Node> Adj[MAXV];
    int n,m, st, ed, weight[MAXV];
    int d[MAXV], w[MAXV], num[MAXV];
    set<int> pre[MAXV];


    void Bellman(int s){
        fill(d, d+MAXV, INF);
        memset(num, 0, sizeof(num));
        memset(w, 0, sizeof(w));
        d[s] = 0;
        w[s] = weight[s];
        num[s] = 1;
        for(int i=0;i<n-1;i++){
            for(int u=0;u<n;u++){
                for(int j=0;j<Adj[u].size();j++){
                    int v = Adj[u][j].v;
                    int dis = Adj[u][j].dis;
                    if(d[u] + dis <d[v]){
                        d[v] = d[u] + dis;
                        w[v] = w[u] + weight[v];
                        num[v] = num[u];
                        pre[v].clear();
                        pre[v].insert(u);

                    }else if(d[u] + dis == d[v]){
                        if(w[u] + weight[v] > w[v]){
                            w[v] = w[u] + weight[v];

                        }
                        pre[v].insert(u);
                        num[v] = 0;
                        set<int>::iterator it;
                        for(it = pre[v].begin();it!=pre[v].end();it++){
                            num[v] += num[*it];
                        }
                    }
                }
            }
        }
    }

    void test(){
        cin >> n >> m >> st;
        for(int i=0;i<n;i++){
            cin >> weight[i];
        }
        int u, v, wt;
        for(int i=0;i<m;i++){
            cin >> u >> v >> wt;
            Adj[u].push_back(Node(v,wt));
            Adj[v].push_back(Node(u, wt));
        }
        Bellman(st);
        cout << num[ed] << w[ed] << endl;
    }
};