#include<iostream>
#include<algorithm>
using namespace std;

const int INF = 100000000;
const int MAXV = 200;
int n,m;
int dis[MAXV][MAXV];

void Floyd(){
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dis[i][k] != INF && dis[k][j] != INF && dis[i][k] + dis[k][j] < dis[i][j]){
                    dis[i][j] = dis[i][k] + dis[k][j];
                }
            }
        }
    }
}

void test(){
    int u,v,w;
    fill(dis[0], dis[0]+ MAXV*MAXV, INF);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        dis[i][i] = 0;
    }
    for(int i=0;i<m;i++){
        cin >> u >> v >> w;
        dis[u][v] = w;
    }
    Floyd();
    for(int i = 0;i < m;i++){
        for(int j=0;j < n;j++){
            cout <<  dis[i][j] << " ";
        }
        cout << endl;
    }
}