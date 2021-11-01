// 238. 除自身以外数组的乘积
#include <vector>
using namespace std;
class Solution { // 被0干扰的失效答案
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> theProduct;
        int len = nums.size();
        int flag = 0;
        if(nums[0] == 0){
            ++flag;
        }
        theProduct.push_back(nums[0]);
        // bool flag = false;  //确定没有0

        for(int i = 1;i < len;++i){
            if(nums[i] == 0){
                ++flag;
                theProduct.push_back(0);
                continue;

            }
            theProduct.push_back(nums[i]*(theProduct[i-1] ? theProduct[i-1] : theProduct[i-2])); //这里的设置， 如果说nums[i-1] 为0 
        }   
        int maxpr = theProduct[len-1];
        for(int i = 0;i<len;++i){
            if(flag > 1){
                // 有两个0， 那么必为0
                theProduct[i] = 0;
            }
            // theProduct[i] = maxpr/nums[i];
            else if(flag == 1 && nums[i] == 0){
                theProduct[i] = maxpr;
            }
            else if(flag == 1 && nums[i]!=0){
                theProduct[i] = 0;
            }
            else{
                theProduct[i] = maxpr/nums[i];
            }
        }
        return theProduct;
    }
};

// 既然使用 product[i] / nums[i] 会在nums[i]的时候失效， 那么不如， 以i的左右各构建一个数组
class Solution1{
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> left(len, 1);
        vector<int> right(len, 1);
        for(int i = 1;i < len;++i){
            left[i] = nums[i-1] * left[i-1]; // i-1 的左边数组 和 nums[i-1]相乘， 就是left[i]
        }
        for(int i = len-2;i >= 0;--i){
            right[i] = nums[i+1] * right[i+1];
        }

        // vector<int> res;
        for(int i = 0;i < len;++i){
            left[i] = left[i] * right[i];
        }
        return left;
    }
};

//  优化空间， 将right 数组用一个常数代替
class Solution2{
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> left(len, 1);
        vector<int> right(len, 1);
        for(int i = 1;i < len;++i){
            left[i] = nums[i-1] * left[i-1]; // i-1 的左边数组 和 nums[i-1]相乘， 就是left[i]
        }
        for(int i = len-2;i >= 0;--i){
            right[i] = nums[i+1] * right[i+1];
        }

        // vector<int> res;
        for(int i = 0;i < len;++i){
            left[i] = left[i] * right[i];
        }
        return left;
    }
};

int main()
{
    vector<int> input = {-1,1,0,-3,3};
    Solution sl;
    sl.productExceptSelf(input);

}