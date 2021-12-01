/*
 * @Date: 2021-11-21 10:50:16
 * @LastEditors: kafier
 * @LastEditTime: 2021-11-21 16:00:45
 */
// 【题目】

// 给定一个长度为N的整型数组arr,其中有N个互不相等的自然数1~N，请实现arr的排序，但是不要把下标0~N-1位置上的数通过直接赋值的方式替换成1~N。

// 【要求】

// 时间复杂度为O(N),额外空间复杂度为O(1)

#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

// 2 1 3 4 
// 2 3 1 4 
// 4312
// INT_MAX
void sort(vector<int>& arr)
{
    // pair<int, int> theswapindex;
    int size = arr.size();
    for(int i = 0;i < size;++i){
        while(arr[i] != i+1){
            swap(arr[i], arr[arr[i]-1]);
        }
    }
}
void print(vector<int>& arr){
    int len = arr.size();
    for(int i  = 0;i < len;++i){
        cout << arr[i];
    }
    cout  << endl;
}

int main(){
    vector<int> arr = {4,3,1,2};
    sort(arr);
    print(arr);
}

// int selectBound(vector<int>& arr, int left, int right){
//     while(left < right){
//         while(left < right && arr[left] < arr[right])
//         {
//             --right;
//         }

//         int temp = arr[right];
//         arr[right] = arr[left];
//         arr[left] = temp;

//         while(left<right && arr[left] < arr[right]){
//             ++left;
//         }
//         temp = arr[right];
//         arr[right] = arr[left];
//         arr[left] = temp;
//     }
//     return left;
// }

// void quickSort(vector<int>& arr, int left, int right)
// {
//     int 
//     quickSort(arr, )
// }
// void sort(vector<int> arr){

// }
