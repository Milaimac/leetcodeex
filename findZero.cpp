// 找零钱
// 背包问题
#include<iostream>
#include<vector>
#include<ctime>
using namespace std;

int findzero(int N){
    int shexxia = 1024-N;
    int count = 0;
//     int num1 = 64, num2 = 16, num3 = 4, num4 = 1;
    vector<int> num_money = {64, 16, 4, 1};
    while(shexxia != 0){
        for(int i=0;i<num_money.size();){
            if(shexxia == 0){
                break;
            }
            if(shexxia - num_money[i] >= 0){
                count++;
                shexxia -= num_money[i];
                continue;
            }else{
                i++;
            }
        }
    }
    return count;
}
int findzero_1(int N){
    int shexxia = 1024-N;
    int count = 0;
//     int num1 = 64, num2 = 16, num3 = 4, num4 = 1;
    vector<int> num_money = {64, 16, 4, 1};
    while(shexxia != 0){
        for(int i=0;i<num_money.size();){
            if(shexxia == 0){
                break;
            }
            if(shexxia / num_money[i] != 0){
                count += shexxia / num_money[i];
                shexxia %= num_money[i];
                i++;
            }
        }
    }
    return count;
}
int main(){
    int N;
    cin >> N;
    clock_t start = clock();
    int res = findzero(N);
    clock_t end = clock();
    cout << (end -start)*1000 << "ms" << endl;
    cout << res << endl;
    return 0;
}