// 给定二维数组， 数组中为0或1, 1为障碍，给定初始坐标（x， y)，给定目的地（x， y） 每一步可以上下左右移动，求出初始到结束的最短路径     


// 思路： 使用bfs遍历图

#include<iostream>
#include<queue>
using namespace std;
struct Piont
{
    int x,y,s;
};

int a[105][105];
int n,m, x1, y1, x2,y2, v[105][105];
queue<Piont> q;

int main(){
    int t; cin >> t;
    while(t--){
        cin>>m>>n>>y1>>x1>>y2>>x2;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                v[i][j] = 0;
            }
        }
        while(!q.empty()){
            q.pop();
        }

        if(x1 == x2 && y1 == y2){
            cout << "1" << endl;
        }

        Piont p;
        p.x = x1,p.y = y1, p.s = 1;
        q.push(p);
        bool flag = false;
        while(!q.empty()){
            p = q.front();
            q.pop();
            if(p.x < 0 || p.x >= n; p.y < 0|| p.y >= m){
                continue;
            }
            if(v[p.x][p.y]||a[p.x][p.y]){
                //遇到墙， pass， 之前通过的pass
                continue;
            }

            if(p.x == x2 && p.y == y2){
                flag = true;
                cout << p.s << endl;
                break;
            }

            v[p.x][p.y] = 1;
            Piont p1;p1.x = p.x+1;p1.y = p.y;p1.s = p.s+1;q.push(p1);
            Piont p2;p2.x = p.x-1;p2.y = p.y;p2.s = p.s+1;q.push(p2);

            Piont p3;p3.x = p.x;p3.y = p.y+1;p3.s = p.s+1;q.push(p3);
            Piont p4;p4.x = p.x;p4.y = p.y-1;p4.s = p.s+1;q.push(p4);
        }
        if(!flag){
            cout << -1 << endl;
        }
    }   
}
