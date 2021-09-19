#include <iostream>
#include <vector>
#include <limits>
using namespace std;

class MergeSort{
public:
    void sort(vector<int> &arr){
        vector<int> tmp = vector<int> (arr.size());
        sort(arr, 0,arr.size()-1, tmp);
    }
    void sort(vector<int> &arr, int left, int right, vector<int> temp){
        if(left < right){
            int mid = left + (right-left)/2;
            sort(arr, left, mid, temp);
            sort(arr, mid+1, right, temp);
            merge(arr, left, mid, right, temp);
        }
    }

    void merge(vector<int> &arr, int left,int mid,  int right, vector<int> tmp){
        int i = left;       // 左序列指针
        int j = mid+1;      // 右序列指针
        int t = 0;          // 临时数组指针
        while(i<= mid && j<=right){
            if(arr[i] <= arr[j]){
                tmp[t++] = arr[i++];
            }else{
                tmp[t++] = arr[j++];
            }
        }
        while(i <= mid){
            tmp[t++] = arr[i++];
        }
        while(j <= right){
            tmp[t++] = arr[j++];
        }

        t = 0;
        while(left <= right){
            arr[left++] = tmp[t++];
        }

    }

};
class Mergesortv2{
public:
    void mergeSort(vector<int>& nums, int left, int right, vector<int> tmp){
        if(left == right){
            return ;
        }
        int mid = left+(right-left)/2;
        mergeSort(nums, left, mid, tmp);
        mergeSort(nums, mid+1, right, tmp);
        Merge(nums, left, mid,right,tmp);

    }
    // Merge 的时候必须假定left -- mid， mid+1 --right已经排序好了
    void Merge(vector<int>& nums, int left, int mid, int right, vector<int> tmp){
        for(int i = left;i <= right; ++i){
            tmp[i] = nums[i];
        }

        int idexleft = left;
        int idexright = mid+1;
        for(int k = left;k<=right;k++){     //这个就是debuf最终发现的错误，k必须到right，否则就会把大的数给丢弃掉。
            if(idexleft == mid+1){
                nums[k] = tmp[idexright];
                idexright++;
            }   
            else if(idexright == right+1){
                nums[k] = tmp[idexleft];
                idexleft++;
            }
            else if(tmp[idexleft] <= tmp[idexright]){
                nums[k] = tmp[idexleft];
                idexleft++;
            }else{
                nums[k] = tmp[idexright];
                idexright++;    
            }
        }
    }
    Mergesortv2(vector<int>& nums){
        tmp.resize(nums.size());
        mergeSort(nums, 0, nums.size()-1, tmp);
    }
    vector<int> tmp;
};

class Mergetsortv1{
public:
    void Merge(vector<int> &array, int front, int mid, int end){
        // vector<int> leftSubArray(array.begin()+front, array.begin()+mid+1);
        // 之所以在end之后+1，是为了避免递归到最后的时候end=1， mid = 0, 从而leftSubArreay没有创建
        // 但是end = 1， mid = 0， mid + 1 = 1两个都为空数组
        // 
        vector<int> leftSubArray(array.begin()+front, array.begin()+mid+1);
        vector<int> rightSubArray(array.begin()+mid+1, array.begin()+end+1);
        int idxleft = 0, idxRight = 0;
        // 为什么要在两个子序列中插入最大值
        // 首先最大值的存在是不可能放入array的，因为insert前的leftsubarray的大小为 mid+1-front, rightsubarray的大小为end+1-(mid+1) 就是end-fornt+1  
        leftSubArray.insert(leftSubArray.end(), numeric_limits<int>::max());
        rightSubArray.insert(rightSubArray.end(), numeric_limits<int>::max());
        for(int i = front;i<=end;++i){
            if(leftSubArray[idxleft] < rightSubArray[idxRight]){
                array[i] = leftSubArray[idxleft];
                idxleft++;
            }
            else{
                array[i] = rightSubArray[idxRight];
                idxRight++;
            }
        }
    }
    void Mergesort(vector<int> &arrar, int front, int end){
        if(front >= end){
            return ;
        }
        int mid = (front+end)/2;
        Mergesort(arrar, front, mid);
        Mergesort(arrar, mid+1, end);
        Merge(arrar, front, mid, end);
    }
    Mergetsortv1(vector<int> &arr){
        Mergesort(arr, 0, arr.size()-1);
    }
};
int main(){
    vector<int> arr = {7,5,6,4,2,1};
    Mergesortv2 sl(arr);
    // MergeSort SL;
    // SL.sort(arr);
    for(auto& ele:arr){
        cout << ele << " ";
    }
    cout << endl;
}

