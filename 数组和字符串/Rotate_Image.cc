// 48. 旋转图像
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    // 方法1，就是直接创建个新的矩阵来存放， 但不符合原地旋转

    // 如果要做到原地旋转， 就必须要覆盖原先的元素， 如何避免这种情况？
    // 使用一个temp存取最初被替代的值， 然后递推得到四次元素旋转便回到起始的位置
    // 如何遍历？
    // 如果n是偶数， 那么只需要遍历 [0 - n/2,0 -n-2]
    // 如果n是奇数， 那么只需要遍历 [0 - n/2, 0- n/2+1];


    //时间复杂度为 o(n^2/4)
    // 空间复杂度 O(1)
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // 奇数
        for(int i = 0;i < n/2;++i)
        {
            for(int j = 0;j <(n+1)/2;++j)
            {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[n-j-1][i];     //写反了 ， matrix[j][n-i+1] = matrix[i][j]
                matrix[n-j-1][i] = matrix[n-i-1][n-j-1];
                matrix[n-i-1][n-j-1] = matrix[j][n-i-1];
                matrix[j][n-i-1] = temp;
            }
        }
    }


    void rotatev1(vector<vector<int>>& matrix)
    {
        // 水平翻转后， 再是对角线翻转就可以得到 旋转数组
        int n = matrix.size();
        for(int i = 0;i<n/2;++i)
        {
            for(int j = 0;j<n;++j)
            {
                swap(matrix[i][j], matrix[n-i-1][j]);
            }
        }

        for(int i = 0;i<n;++i)
        {
            for(int j=0;j<i;++j)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};