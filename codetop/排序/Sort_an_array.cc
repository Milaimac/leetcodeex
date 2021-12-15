/*
 * @Date: 2021-11-27 15:55:36
 * @LastEditors: kafier
 * @LastEditTime: 2021-12-05 18:21:30
 */
#include <vector>
#include <random>
using namespace std;
class Solution
{
public:
    vector<int> sortArray(vector<int> &nums)
    {
    }
    void quickSort(vector<int> &nums, int left, int right)
    {
        if (left < right)
        {
            int location = randomPartition(nums, left, right);
            quickSort(nums, left, location - 1);
            quickSort(nums, location + 1, right);
        }
    }

    inline int partition(vector<int> &nums, int left, int right)
    {
        int x = nums[right], i = left - 1;
        for (int j = 0; j < right; ++j)
        {
            if (nums[j] < x)
            {
                swap(nums[++i], nums[j]);
            }
        }
        swap(nums[i + 1], nums[right]);
        return i + 1;
    }
    inline int randomPartition(vector<int> &nums, int left, int right)
    {
        int i = rand() % (right - left + 1) + left;
        swap(nums[i], nums[right]);
        return partition(nums, left, right);
    }
};

class MergeSolution
{
public:
    vector<int> tmp;
    vector<int> sortArray(vector<int> &nums)
    {
        tmp.resize((int)nums.size(), 0);
        mergeSort(nums, 0, (int)nums.size() - 1);
        return nums;
    }

    void mergeSort(vector<int> &nums, int left, int right)
    {
        if (left >= right)
        {
            return;
        }
        int mid = left + (right - left) / 2;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);

        int i = left, j = mid + 1;
        int cnt = 0;
        while (i <= mid && j <= right)
        {
            if (nums[i] <= nums[j])
            {
                tmp[cnt++] = nums[i++];
            }
            else
            {
                tmp[cnt++] = nums[j++];
            }
        }
        // 如果右边的区间先被放完了
        while (i <= mid)
        {
            tmp[cnt++] = nums[i++];
        }
        // 如果是左边的区间先被放完了
        while (j <= right)
        {
            tmp[cnt++] = nums[j++];
        }

        for (int i = 0; i < right - left + 1; ++i)
        {
            nums[i + left] = tmp[i];
        }
    }
};

class HeapSolution {
public:
    vector<int> sortArray(vector<int>& nums) {
        heapSort(nums);
        return nums;
    }

    void maxHeapify(vector<int>& nums, int i, int len)
    {
        // (i<<1) == i*2
        while((i<<1)+1 <= len)
        {
            int lson = (i<<1) + 1;
            int rson = (i<<1) + 2;

            int large;
            // 如果i的左子节点大于根节点 large = lson, 否则 large = i
            if(lson <= len && nums[lson] > nums[i])
            {
                large = lson;
            }
            else{
                large = i;
            }
            //如果右节点比现在（根节点和左节点）都要大， large = rson
            if(rson <= len && nums[rson] > nums[large])
            {
                large = rson;
            }
            // 根节点不大。 
            if(large != i)
            {
                swap(nums[i], nums[large]);
                i = large;
            }
            else{
                break;
            }
        }
    }

    void buildMaxHeap(vector<int>& nums, int len)
    {
        // 如果有n个节点， 由二叉树的性质。假设最后一层的节点的数量为k， 那么上层的节点为 k/2 + k/4+ .. + 1， 化为等差数列可以得到k-1
        // 所以二叉树的一半 + 1就是叶子节点的数量
        // 那么第一个非叶子节点的索引就是 (len - 1)/2;
        for(int i = len/2; i>=0;--i)
        {
            maxHeapify(nums, i, len);
        }
    }

    void heapSort(vector<int>& nums)
    {
        // 循环不变量：区间[0,i]堆有序
        int len = (int)nums.size() - 1;
        buildMaxHeap(nums, len);
        // 把堆顶元素（当前最大）交换到数组末尾
        for(int i = len;i >= 1;--i)
        {
            swap(nums[i], nums[0]);
            // 减少堆有序的部分
            len -=1;
            maxHeapify(nums, 0, len);
        }
    }
};