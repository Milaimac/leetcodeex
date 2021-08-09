#include<iostream>
#include<vector>
using namespace std;

// 运用前缀和的思想， 将arr数组
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n=arr.size();
        vector<int> xors(n+1);
        for(int i=0;i<xors.size();i++){
            xors[i+1] = xors[i]^arr[i];
        }
        
        int nums = queries.size();
        vector<int> res(nums);
        for(int i=0;i<nums;i++){
            res[i] = xors[queries[i][0]] ^ xors[queries[i][1]+1];
        }
        return res;
    }
};