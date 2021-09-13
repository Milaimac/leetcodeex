#include<vector>
#include<string>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<string> permutation(string s) {
        // for(auto& ch:s){
        //     charvec.push_back(ch);
        // }
        used.resize(s.size(), false);
        string path;
        sort(s.begin(), s.end());
        backtrack(s, path, used);
        return ret;
    }

    void backtrack(string &s, string path, vector<bool> used){
        if(path.size() == s.size()){
            ret.push_back(path);
            return;
        }
        // 不允许同样的字符排列
        for(int i =0;i<s.size();++i){
            if(used[i] || (i>0&&!used[i] && s[i] == s[i-1])){ //bug  如果单纯s[i] == s[i-1]就跳过的话，那么path就没有机会加入aa这相同的词, 所以我加入了used[i]啊
                continue;
            }
            path.push_back(s[i]);
            used[i] = true;
            backtrack(s, path, used);
            used[i] = false;
            path.pop_back();
            // if(!used[i]){
                // path.push_back(s[i]);
                // used[i] = true;
                // backtrack(s, path, used);
                // used[i] = false;
                // path.pop_back();
            // }
        }
    }
private:
    // vector<char> charvec;
    vector<bool> used;
    vector<string> ret;
};


int main(){
    string s = "aab";
    Solution sl;
    sl.permutation(s);
}