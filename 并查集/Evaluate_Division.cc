/*
 * @Date: 2021-11-05 14:52:18
 * @LastEditors: kafier
 * @LastEditTime: 2021-11-06 11:23:16
 * @FilePath: /leetcodeex/并查集/Evaluate_Division.cc
 * 压缩法，除法的关系构建出一个图， 倍数关系 为  权值关系 ， 对应的字符常量 是 节点， 为了能够使用并查集方便， 需要使用哈希表将之编码
 * 在路径压缩的时候更新权值变化（Find） 在合并的时候使用公式计算权值 
 * 在最终的判断是否连接isConnected ， 计算其中的比值
 */

#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;


// 使用并查集， 将能够连通的节点合并到同一个集合

// 路径压缩 要注意将权值相乘， 可以通过现时计算靠近根节点的权值， 以后优化下面节点的权值
// 在合并的操作， 维护权值的变化
//  990 另一种压缩法

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // equations
        int equal_sz = equations.size();
        //为什么是2倍的长度 ———————— 由于不能直接冲eqautions 得知全部节点的个数， 那么就设置其中最大的节点数量为eqations.size 
        UnionFind(2*equal_sz);
        // 需要设置一个哈希表实现并查集的映射
        unordered_map<string, int> hashMap(2*equal_sz);
        // 设为从1开始， 方便设置0作为一个查找不到的值 ———————— 还是改为了0
        int id = 0;
        // 对equations的节点 进行编码 从字符串到整型
        for(int i = 0; i < equal_sz;++i){
            string var1 = equations[i][0];
            string var2 = equations[i][1];
        
            if(!hashMap.count(var1)){
                hashMap[var1] = id;
                ++id;
            }
            if(!hashMap.count(var2)){
                hashMap[var2] = id;
                ++id;
            }
            // 随后合并两个节点, hashMap和parents的不同步
            Union(hashMap[var1], hashMap[var2], values[i]);
        }

        // 第二步 ， 做查询, 在查询的时候
        int queries_size = queries.size();
        vector<double> res(queries_size);

        for(int i = 0;i < queries_size; ++i){
            string var1 = queries[i][0];
            string var2 = queries[i][1];

            // 如果是没有创建过的


            if(hashMap.count(var1) == 0 || hashMap.count(var2) == 0){
                res[i] = -1.0;
            }
            else{
                int id1 = hashMap[var1];        
                int id2 = hashMap[var2];
                res[i] = isConnected(id1, id2);
            }
        }

        return res;

    }
private:
    vector<int> parent;
    vector<double> weight;
    void UnionFind(int n){
        parent = vector<int>(n);
        weight = vector<double>(n);
        // 一开始的初始化， 自己就是根节点
        for(int i = 0;i < n;++i){
            parent[i] = i;
            weight[i] = 1.0;
        }
    }
    // 合并的时候
    void Union(int x, int y, double value){
        // 顺带着在查询的时候进行了权值
        int rootx = Find(x);
        int rooty = Find(y);
        if(rootx == rooty){
            return ;
        }

        parent[rootx] = rooty;
        // 要将两个节点合并为同一个并查集， 
        weight[rootx] = (weight[y] * value) / weight[x];
    }
    // 路径压缩
    int Find(int x){
        if(x != parent[x]){
            // 为了考虑权值的变化, 根据上一个节点的权值变化
            int origin = parent[x];
            parent[x] = Find(parent[x]);
            weight[x] *= weight[origin];
        }
        return parent[x];
    }
    // 判断两个节点是否在同一个集合
    double isConnected(int x,int y){
        int rootX = Find(x);
        int rootY = Find(y);
        if(rootX == rootY){
            return weight[x]/weight[y];
        }else{
            return -1.0;
        }
    }

};

int main(){
    vector<vector<string>> eqations = {{"a", "b"}};
    vector<double> values = {0.5};
    vector<vector<string>> queries = {{"a","b"},{"b","a"},{"a","c"},{"x","y"}};

    Solution sl;
    vector<double> res = sl.calcEquation(eqations, values, queries);
    for(auto& r:res){
        cout << r << " ";
    }
    cout << endl;
}



// 注意点之一 ： 合并的公式
