//2. 心算挑战
#include<algorithm>
#include<vector>
using namespace std;


//规律： 偶个奇数相加为偶数， 偶数和偶数相加必为 偶数
class Solution {
public:
    int maxmiumScore(vector<int>& cards, int cnt) {
        vector<int> a[2], s[2];// 两个vector数组, a这个数组将偶数和奇数分开， 不过是单个数， s这个数组将会得到累加和
        for(auto& card:cards){
            a[card&1].push_back(card);
        }
        
        for(int i = 0 ;i<2;++i){
            sort(a[i].begin(), a[i].end());
            s[i].resize(a[i].size()+1, 0);
            for(int j = 0;j<a[i].size();++j){
                s[i][j+1] = s[i][j] + a[i][j];
            }
        }
        int ans;
        for(int i = 0;i<cnt && i < a[1].size();i+=2){
            if(cnt-i < a[0].size()){
                ans = max(ans, s[0].back() + s[1].back() - s[0][a[0].size() - cnt + i] - s[1][a[1].size()-i]);
            }
        }
        return ans;
    }
};
