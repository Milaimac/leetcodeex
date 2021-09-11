#include<vector>
#include<iostream>
using namespace std;

// 1. 直接模拟，超时
// 2. 取余
class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int i = 0;
        int sum  = 0;
        for(auto &ele:chalk){
            sum += ele;
        }

        int re = k%sum;

        while(i < chalk.size()){
            if(re >= chalk[i]){
                re -= chalk[i];
                i = (i+1)%chalk.size();
            }
            else{
                break;
            }
        }

        return i;
    }
};



int main(){
    vector<int>  chalk = {1};
    Solution sl;
    cout << sl.chalkReplacer(chalk, 1000000000) << endl;
}