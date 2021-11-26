/*
 * @Date: 2021-11-23 16:09:15
 * @LastEditors: kafier
 * @LastEditTime: 2021-11-25 14:50:08
 */
#include <vector>
#include <random>
using namespace std;

class Solution
{
public:
    /**
     * @description: 
     * 改进快速排序
     * 快速排序的想法， 就是通过基准点bound，数组中[0, ... , bound-1]的数小于 arr[bound], 其中数组中[bound+1, len) 的数大于 arr[bound]
     * 快排的思路： 划分 -- > 解决 --> 合并（不需要）
     * 我们每经过一次划分， 一定可以知道的那个一个元素的最终位置， 所以只要某次划分的q为倒数第k个下标的时候， 我们就找到了答案。 
     * 这样。 我们就不需要关心 a[l,..q-1] 和 a[q+1..r]是否是有序的 。
     * 改进快速排序算法： 我们在划分的时候， 如果划分得到的q正好是我们要的下表， 那么直接返回。 如果q比目标下标小， 就递归右子区间
     * 
     * 这个改进思想就是分治思想
     * @param {int} k
     * @return {*}
     */
    int qiuckSelect(vector<int> &a, int l, int r, int index)
    {
        int q = randomPartition(a, l, r);
        if (q == index)
        {
            return a[q];
        }
        else
        {
            return q < index ? qiuckSelect(a, q + 1, r, index) : qiuckSelect(a, l, q - 1, index); // 这个有点像二分了
            
        }
    }
    inline int partition(vector<int> &a, int l, int r)
    {
        int x = a[r], i = l - 1;
        // 对于
        for (int j = l; j < r; ++j)
        {
            if (a[j] <= x) // 如果要实现降序， 那么把整个改成 a[j] > x就可以了吗
            { // 将小于基准值排到从l开始的部分
                swap(a[++i], a[j]);
            }
        }
        // 其中用i记下在[l , r]范围内小于基准值的末尾坐标, 而后找到其中的位置
        swap(a[i + 1], a[r]);
        return i + 1;
    }
    inline int randomPartition(vector<int> &a, int l, int r)
    {
        // 随意找一个点和右边界交换， 以这个点作为基准值进行划分
        int i = rand() % (r - l + 1) + l;
        swap(a[i], a[r]);
        return partition(a, l, r);
    }
    int findKthLargest(vector<int> &nums, int k)
    {
        srand(time(0));
        return qiuckSelect(nums, 0, nums.size() - 1, nums.size() - k);
    }
};


