/*
 * @Date: 2021-12-03 15:47:52
 * @LastEditors: kafier
 * @LastEditTime: 2021-12-04 11:28:11
 */
#include <vector>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(); 
        for(int i = 0;i < m;++i){
            if(binarySearch(matrix, target, i)){
                return true;
            }
        }
        return false;
    }

    bool binarySearch(vector<vector<int>>& matrix, const int& target,const int& row){
        int n = matrix[0].size();
        int left = 0, right = n;
        while(left < right){
            int mid = left + (right - left) / 2;
            if(matrix[row][mid] == target){
                return true;
            }
            else if(matrix[row][mid] < target){
                left = mid+1;
            }
            else{
                right = mid;
            }
        }
        return false;
    }
};