#include<vector>
#include<iostream>
#include<random>
using namespace std;
// 面试题 17.14. 最小K个数

// 直接使用快排
class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        QuickSort(arr, 0, arr.size()-1);
        vector<int> res(k);
        for(int i =0;i<k;i++){
            res[i] = arr[i];
        }
        return res;
    }

    void QuickSort(vector<int>& arr, int begin, int end){
        if(begin > end){
            return;
        }
        //已某个数为基准值，将数组的所有数移动，小于这个基准值的数在左边，大于这个基准值的数在右边
        //用high和low，当发现arr[high]有小于这个基准值的，（暂且不急着swap，而是等i也找到了相应的大于基准值的数，才进行swap）
        // 最终等到i == j的时候，将这个索引对应的值和原来的第一个基准值调换

        //接下来就是分治基准值的左边和右边，用同样的办法去快排
        int tmp  = arr[begin];
        int i = begin;
        int j = end;
        while(i != j){
            // 先j后i，先让j移到小于基准值的数，这样即便重合了，交换也不会出现问题
            while(arr[j] >= tmp && j > i){
                --j;
            }
            while(arr[i] <= tmp && i < j){
                ++i;
            }
            if(j > i){
                int t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;
            }
        }
        arr[begin] = arr[i];
        arr[i] = tmp;
        QuickSort(arr, begin, i-1);
        QuickSort(arr, i+1, end);
    }
};


// 如何利用快排的思想

// 要求找到最小的k数，那么如何递归
// 如果发现左边不够k个数，那就pos向右移动
// 定义函数randomized-selected(arr, 1, r, k)表示划分数组arr的[1,r]部分，使前k小的数在数组左侧
class Solutionv1 {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        srand((unsigned)time(NULL));
        vector<int> res(k);
        for(int i = 0;i<k;i++){
            res[i] = arr[i];
        }
        return res;
    }
private:
    // 使用Partiton完成对于基准值的排序 (x)
    // 使用Partitioin找到比pivot小的数和大的数之间的index索引值

    int  Partition(vector<int>& arr,int left, int right){
        int pivot = arr[right];
        int i = left-1;
        for(int j = left;j <= right-1;j++){
            if(arr[j] <= pivot){
                i += 1;
                swap(arr[j], arr[i]);
            }
        }
        swap(arr[i+1], arr[right]);
        return i+1;

    }
    
    int RandomPartition(vector<int>& arr, int left, int right){
        int i  = rand() %(right-left + 1) + left;
        swap(arr[i], arr[right]);
        // int postion = Partition(arr, left, right);
        return Partition(arr, left, right);
    }

    void  RandomSelect(vector<int>& arr, int left, int right, int k){
        if(left >= right){
            return;
        }
        int pos = RandomPartition(arr, left, right);
        int sum = (pos - left) + 1;
        if(sum == k){
            return;
        }

        if(sum > k){
            RandomSelect(arr, left, pos-1, k);
        }else if(sum < k){
        
            RandomSelect(arr, pos+1, right, k-sum);
        }

    }
};
int main(){
    vector<int> input = {1,3,5,7,2,4,6,8};
    Solution sl;
    auto res = sl.smallestK(input, 3);
    for(auto &ele:res){
        cout << ele << " ";
    }
    cout << endl;
}      



class Solution {
    int partition(vector<int>& nums, int l, int r) {
        int pivot = nums[r];
        int i = l - 1;
        for (int j = l; j <= r - 1; ++j) {
            if (nums[j] <= pivot) {
                i = i + 1;
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[i + 1], nums[r]);
        return i + 1;
    }

    // 基于随机的划分
    int randomized_partition(vector<int>& nums, int l, int r) {
        int i = rand() % (r - l + 1) + l;
        swap(nums[r], nums[i]);
        return partition(nums, l, r);
    }

    void randomized_selected(vector<int>& arr, int l, int r, int k) {
        if (l >= r) {
            return;
        }
        int pos = randomized_partition(arr, l, r);
        int num = pos - l + 1;
        if (k == num) {
            return;
        } else if (k < num) {
            randomized_selected(arr, l, pos - 1, k);
        } else {
            randomized_selected(arr, pos + 1, r, k - num);
        }
    }

public:
    vector<int> smallestK(vector<int>& arr, int k) {
        srand((unsigned)time(NULL));
        randomized_selected(arr, 0, (int)arr.size() - 1, k);
        vector<int> vec;
        for (int i = 0; i < k; ++i) {
            vec.push_back(arr[i]);
        }
        return vec;
    }
};

