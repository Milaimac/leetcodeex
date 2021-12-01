/*
 * @Date: 2021-11-27 15:55:36
 * @LastEditors: kafier
 * @LastEditTime: 2021-11-27 16:00:19
 */
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {

    }
    void quickSort(vector<int>& nums)
    {
        
    }

    int partition(vector<int>& arra, int low, int high)
    {

        // 从最左边的那个数作为基准。 这个称为划分操作 ：： 划分操作实现数字的定位
        while(low < high)
        {
            while(low < high && arra[low] <= arra[high])
            {
                --high;
            }
            swap(arra[low], arra[high]);
            
            while(low < high && arra[low] <= arra[high])
            {
                ++low;
            }
            swap(arra[low], arra[high]);
        }
        return low;
    }
};