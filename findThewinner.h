#include<map>
#include<vector>
using namespace std;
/*
class Solution {
public:
    int findTheWinner(int n, int k) {pub
        int i =0;
        int win,res, max_nums=n;
        map<int ,int> loser_map;
        
        while(i < max_nums){
            i+=k;
            if(max_nums < i){
                i -= max_nums;
            }
            if(max_nums == i){
                for(int j = max_nums-1;j>0;j--){
                    if(loser_map.find(j) == loser_map.end()){
                        max_nums = j;
                    }
                }
            }
            loser_map.insert({i, i});
            if(loser_map.size() == n-1){
                break;
            }
        }
        for(int j=1;j<=n;++j){
            if(loser_map.find(j) == loser_map.end()){
                res = j;
            }
        }
        return res;
    }
};
*/
class Solution{
public:
    int findTheWinner(int n, int k){
        vector<int> a(n);
        for(int i=0;i<n;i++){
            a[i] = i+1;
        }       
        int at=0;
        while(a.size() > 1){
            at=(at+k-1)%a.size();
            a.erase(a.begin() + at);

        }           

        return a[0];
    }
};