#include<iostream>
#include<string>
#include<map>
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
int main(){
    string str;
    cin >> str;
    unordered_map<char, int> umap;
    int len = str.length();
    int dp = INT_MAX, length = 0;
    int diff = 0;
    map<char, int> umap1;
    // unordered_map<int,int> resmap;
    vector<pair<int, int> > resmap;
    for(int i = 0;i<len;i++){
        if(umap1[str[i]] == 0){
            umap1[str[i]] += 1;
        }
    }

    for(int i=0;i<len;i++){
        diff = 1;
        // bzero(&umap, sizeof(umap));
        if(umap.size() != 0){
            for(auto iter = umap.begin(); iter != umap.end();iter++){
            iter->second = 0;
            }
        }
        umap[str[i]] = 1;
        
        for(int j=i+1;j<len;j++){
            if(umap[str[j]] == 0){
                umap[str[j]] = 1;
                diff += 1;
                length = j-i+1;
            
                if(diff == umap1.size() && length <= dp){
                    dp = length;
                    // resmap[dp] = i; // 会覆盖掉
                    pair<int,int> rp;
                    rp.first = dp;
                    rp.second  = i; 
                    resmap.push_back(rp);
                    // cout << i << " " << j << length << endl;
                }
            }
            else{
                umap[str[j]] += 1;
                length = j-i+1;
            }
            
        }
    }
    tuple<int, int> res;
    for(auto iter = resmap.begin(); iter != resmap.end();iter++){
        if(iter->first == dp){
            res = {iter->second, iter->first};
            cout << iter->second <<"," << iter->first;
            break;
        }
    }

}