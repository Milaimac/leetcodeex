
#include <vector>
using namespace  std;
// 剑指 Offer 11. 旋转数组的最小数字
class Solution {
public:
    int minArray(vector<int>& numbers) {
        int low = 0, high = numbers.size()-1;

        while(low < high){
            // 如果发现pivot比high大，说明min在右边
            //相反地，min在pivot左边
            int pivot = low + (high-low)/2;
            if(numbers[pivot] > numbers[high]){
                low = pivot+1;
            }
            else if(numbers[pivot] < numbers[high]){
                high = pivot;
            }
            else{
                high--;
            }
        }
        return numbers[low];
    }
};