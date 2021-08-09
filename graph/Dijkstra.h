#include<algorithm>
#include<vector>
using namespace std;
//#ifdef NDEBUG
const int MAXV = 1000;
const int INF = 1000000000;


#ifdef NDEBUG
// �ڽӾ���,�����ڵ�������v������1000�����
int n, G[MAXV][MAXV];			
int d[MAXV];					//��㵽����ĳ���
bool vis[MAXV] = { false };		//������֣�vis[true]��ʾ�Ѿ�������false��ʾû������
void Dijkstra(int s) {//sΪ���
	fill(d, d + MAXV, INF);		//fill����������d���ָ�ΪINF
	d[s] = 0;					//�Լ����Լ��ľ���Ϊ0
	for (int i = 0; i < n; i++) {
		int u = -1, MIN = INF;	//u����С�Ľ��
		for (int j = 0; j < n; j++) {
			if (vis[j] == false && d[j] < MIN) {
				u = j;
				MIN = d[j];
			}
		}
		//�Ҳ���С��INF��d[u]��˵��ʣ�µĽ�㲻��ͨ
		if (u == -1)
			return;

		vis[u] = true;
		//�Ż�·��
		for (int v = 0; v < n; v++) {
			if (vis[u] == false && G[u][v] != INF && d[u] + G[u][v] < d[v]) {
				d[v] = d[u] + G[u][v]; //�Ż�d[v]
			}
		}


	}
}


#endif
//�ڽӱ�
struct Node
{
	int v, dis;
};

vector<Node> Adj[MAXV];		//ͼG��Adj[u]��ŴӶ���u�������Ե�������ж���

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


// �ڽӾ����
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
