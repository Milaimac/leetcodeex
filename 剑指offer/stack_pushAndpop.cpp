#include<vector>
#include<stack>
using namespace std;
// 946. 验证栈序列
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> pu,po;
        for(int i = popped.size()-1;i>=0;--i){
            po.push(popped[i]);
        }

        for(auto &ele:pushed){
            pu.push(ele);
            while(!pu.empty() && !po.empty() && pu.top() == po.top()){
                pu.pop();
                po.pop();
            }
        }

        return pu.empty() && po.empty();
    }
};

class v1Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> po;
        for(int i = popped.size() -1;i>=0;--i){
            po.push(popped[i]);
        }

        for(auto &ele:pushed){
            while(!po.empty() && ele == po.top()){
                po.pop();
            }
        }
    }
};