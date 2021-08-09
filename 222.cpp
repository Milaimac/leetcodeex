#include<iostream>
#include<queue>
using namespace std;
struct Piont{
    int x, y, s;
};
int main(){
    int x1, y1, x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;
    deque<Piont> qqq;
    while(!qqq.empty()){
        qqq.pop_back();
    }
    Piont start;
    start.x = 0;
    start.y = 0;    
    start.s = 0;
    qqq.push_back(start);

    int res = 0;
    if(x2 == 0 && y2 == 0){
        cout << 1 << endl;
    }
    while (!qqq.empty())
    {
        Piont ppp = qqq.front();
        if(ppp.x == x2 && ppp.y == y2){
            res += 1;
        }
        
        if(ppp.x + 1 != x1 && ppp.y != y1 && ppp.x <= x2 && ppp.y <= y2){
            Piont ppp1;
            ppp1.x = ppp.x+2;
            ppp1.y = ppp.y+1;
            ppp1.s = ppp.s + 1;
            qqq.push_back(ppp1);
        }

        if(ppp.x != x1 && ppp.y+1 != y1 && ppp.x <= x2 && ppp.y <= y2 ){
            Piont ppp2;
            ppp2.x = ppp.x+1;
            ppp2.y = ppp.y+2;
            ppp2.s = ppp.s + 1;
            qqq.push_back(ppp2);
        }
        qqq.pop_front();
    }
    cout << res << endl;

}