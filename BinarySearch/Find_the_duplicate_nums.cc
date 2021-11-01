#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:

    // 换种思考方式来， 不是使用原数组来左二分查找
    // 而是用cnt[i] —— cnt[i]指的是Nums中小于等于i的数有多少
    // 那么cnt数组随数组i的增大具有递增性
    // 如果测试用例的数组中， target出现了三次以上， 那么必然有一些数就不在nums数组中了，
    // 如果cnt[i] <=i 那么就是重复数组前的， 如果cnt[i] > i， 那么就是重复数组后， 而我们要查找的数就是第一个cnt > i 的数
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        // 不必修改数组，

        // sort(nums.begin(), nums.end());  不修改数组， 自然就没法调用排序
        int left = 0, right = n-1, ans = -1;
        // 既然会重复的话， 
        // 为什么是大于等于， 为什么有时候又是 大于
        while(left < right){
            int mid = (left+right) >> 1;
            int cnt = 0;
            for(int i=0;i<n;++i){
                cnt += (nums[i] <= mid);
            }
            if(cnt <= mid){
                left = mid+1;
            }
            else{
                ans = mid;
                right = mid;
            }
        }
        return ans;
    }

    // 快慢指针做法
    // 对数组建图， 每个位置i连一条i --- > nums[i]的边。 由于存在重复数字target， 因此target这个位置一定有起码两条指向它的两条边， 所以整个图一定存在环

    // 假设环长为L, 从起点到环入口的步数为a ， 从环的入口继续走到b步达到相遇位置， 从相遇位置继续走c步到环的入口， 则有b+c = L;
    // 慢指针走了a+b步， 快指针走了2(a+b)步， 从另一个角度考虑， 在相遇位置， 快指针比慢指针多走了若干圈 -- a + b + kL
    

    // 2(a+b) = a+b+kL

    int findDuplicate2(vector<int>& nums){
        int slow = 0, fast = 0;
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow != fast);

        slow = 0;
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};

int main(){
    vector<int> vec = {1,1};
    Solution sl;
    sl.findDuplicate(vec);
}


//  通常来说， left = mid + 1, right = mid-1  就应该设置 left <= right
// left = mid+1, right = mid . 应该设置为 left < right
// 但是对于该题的[1,1]示例
// 由于设置left < right 退出过早
// left = 0 right = 1 mid = 0, cnt = 0  --- left = 1, right = 1 mid = 1 ———— 退出循环 over
// 也就是说如果是这样设计的话， mid是无法到达 left 和 right相等的情况。 而对于目前这道题就是mid无法到达right这个位置

// 时间复杂度为 O(nlogn) —————— 二分查找 O(logn) * 每次遍历O(n) 
