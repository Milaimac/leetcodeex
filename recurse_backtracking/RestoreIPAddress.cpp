#include<string>
#include<vector>
#include<iostream>
using namespace std;
// 复原IP地址
class Solution {
private:
    static constexpr int SEG_OUT = 4;
public:
    // vector<string> segment(4);
    vector<string> res;
    vector<int> segement;
    vector<string> restoreIpAddresses(string s) {
        segement.resize(SEG_OUT);
        backtrack(s, 0,0);
        return res;
    }

    void backtrack(string &s, int segId, int Segstart){
        if(segId == SEG_OUT){

            if(Segstart == s.size()){
                string subres;
                // 遍历完字符串了
                for(int i = 0;i<SEG_OUT;++i){
                    subres += to_string(segement[i]);
                    if(i != SEG_OUT-1){
                        subres += ".";
                    }
                }
                res.push_back(move(subres));
            }
            return ;
        }
        // 没有找到4个ip地址，就已经遍历完了字符串
        if(Segstart == s.size()){
            return;
        }
        // 有前导零
        if(s[Segstart] == '0'){
            segement[segId] = 0;
            backtrack(s, segId+1, Segstart+1);
        }

        // 一般情况
        // 对每一种情况进行递归
        int addr = 0;
        for(int segEnd = Segstart;segEnd < s.size(); ++segEnd){
            addr = addr*10 + (s[segEnd]-'0');
            if(addr > 0 && addr <= 0xff){
                segement[segId] = addr;
                backtrack(s, segId+1, segEnd+1);
            }
            else{
                break;
            }
        }
    }
};


int main(){
    string s =  "25525511135";
    Solution sl;
    auto res = sl.restoreIpAddresses(s);
    for(auto el:res){
        cout << el << " ";
    }
}