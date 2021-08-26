// 881. 救生艇
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int i = 0, j = people.size()-1;
        int ans = 0;
        while(i <= j){
            //i <= j 是因为留下来是奇数时，也要继续执行。
            if(people[i] + people[j] > limit){
                --j;
            }
            else{
                ++i;
                --j;
            }
            ++ans;
        }
        return ans;
    }
};