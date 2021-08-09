#include<algorithm>
#include<vector>
using namespace std;
//#ifdef NDEBUG
const int MAXV = 1000;
const int INF = 1000000000;


#ifdef NDEBUG
// 邻接矩阵法,适用于点数不大，v不超过1000的情况
int n, G[MAXV][MAXV];			
int d[MAXV];					//起点到各点的长度
bool vis[MAXV] = { false };		//标记数字，vis[true]表示已经来过，false表示没有来过
void Dijkstra(int s) {//s为起点
	fill(d, d + MAXV, INF);		//fill函数将整个d数字赋为INF
	d[s] = 0;					//自己到自己的距离为0
	for (int i = 0; i < n; i++) {
		int u = -1, MIN = INF;	//u是最小的结点
		for (int j = 0; j < n; j++) {
			if (vis[j] == false && d[j] < MIN) {
				u = j;
				MIN = d[j];
			}
		}
		//找不到小于INF的d[u]，说明剩下的结点不连通
		if (u == -1)
			return;

		vis[u] = true;
		//优化路线
		for (int v = 0; v < n; v++) {
			if (vis[u] == false && G[u][v] != INF && d[u] + G[u][v] < d[v]) {
				d[v] = d[u] + G[u][v]; //优化d[v]
			}
		}


	}
}


#endif
//邻接表法
struct Node
{
	int v, dis;
};

vector<Node> Adj[MAXV];		//图G，Adj[u]存放从顶点u出发可以到达的所有顶点

int n;
int d[MAXV];		//distance
bool vis[MAXV] = { false };

void Dijsktra(int s) {
	fill(d, d + MAXV, INF);
	d[s] = 0;
	for (int i = 0; i < n; i++) {
		int u = -1, MIN = INF;
		for(int j=0;j<n;j++){
			if(vis[j] == false && d[j] < MIN){
				u = j;
				MIN = d[j];
			}
		}
		if(u == -1){
			return;
		}
		vis[u] = true;
		for(int j=0;j<Adj[u].size();j++){
			int v = Adj[u][j].v;
			if(vis[u] == false && d[u]+Adj[u][j].dis < d[v]){
				d[v] = d[u] + Adj[u][j].dis;
			}
		}
	}	
}


// 邻接矩阵版
#include<bits/stdc++.h>
const int  Maxv = 1000;
const int INF = 100000;
int n;
int d[Maxv];
int G[Maxv][Maxv];
int pre[Maxv];
bool vis[Maxv] = {false};

void dijkstra(int s){
	fill(d, d+Maxv, INF);
	for(int i=0;i<n;i++){
		pre[i] = i;
	}
}
