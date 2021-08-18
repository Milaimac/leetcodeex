// 等差数列划分 II 446 

// 用f[i][d] 表示以nums[i]为结尾，d为公差的等差数列

//动态方程为 f[i][d] += f[j][d] + 1;
//由于方差范围比较大，所以不能使用二维数组，而是使用哈希表来做
#include <vector>
#include <unordered_map>
using namespace  std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        vector<unordered_map<long long,int>> f(n);
        int ans = 0;
        for(int i = 0;i<n;i++){          
            for(int j = 0;j<i;j++){
                long long d = 1LL * nums[i] - nums[j];                // 1LL为的是在计算时， 将int 转化为long long 
                auto it = f[j].find(d);                               //find找的是key
                int cnt = it == f[j].end() ? 0 :it->second;           //判断f[j]有多少个以d为公差的等差数列的元素
                ans += cnt;
                f[i][d] += cnt + 1;
            }
        }
        return ans;
    }
};

