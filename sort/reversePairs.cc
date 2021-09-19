#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int reversePairs(vector<int>& nums) {

        int len = nums.size();
        if(len < 2){
            return  0;
        }
        tmp.resize(nums.size());
        // vector<int> copy = vector<int>(nums);
        return Mergesort(nums, 0,  len-1, tmp);
    }

    int Mergesort(vector<int>& nums, int left, int right,vector<int>& tmp){
        if(left == right){
            return 0;
        }

        int mid = left + (right - left) /2;
        int leftcount = Mergesort(nums, left, mid, tmp);
        int rightcount = Mergesort(nums, mid+1, right, tmp);
        return leftcount + rightcount + MergeAndCount(nums, left, mid, right, tmp);
    }

    int MergeAndCount(vector<int>& nums, int left, int mid, int right, vector<int>& tmp){
        int count = 0;
        for(int i = left;i <= right;++i){ //here should be equal
            tmp[i] = nums[i];
        }
        int idxleft = left;
        int idxright = mid+1;
        for(int k = left;k<=right;++k){
            if(idxleft == mid+1){
                nums[k] = tmp[idxright++];
                // idxright++;
            }
            else if(idxright == right+1){
                nums[k] = tmp[idxleft++];
            }
            else if(tmp[idxleft] <= tmp[idxright]){ //应该是去比较tmp的，而不是nums的
                nums[k] = tmp[idxleft++];
            }
            else{
                nums[k] = tmp[idxright++];
                count += (mid - idxleft + 1);
            }

        }
        return count;
    }

    vector<int> tmp;
};


int main(){
    vector<int> arr = {7,5,6,4,2,1};
    Solution sl;
    int res = sl.reversePairs(arr);
    // MergeSort SL;
    // SL.sort(arr);
    for(auto& ele:arr){
        cout << ele << " ";
    }
    cout << endl;

    cout << " res= " << res << endl;
}

