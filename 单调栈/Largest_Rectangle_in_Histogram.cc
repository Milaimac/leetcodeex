// 84. 柱状图中最大的矩形
#include <vector>
#include <iostream>
#include <stack>
using namespace std;
class Solution {
public:
    // 从i到j的面积为 (i-j)* min(for ele in heights[i ... j])
    // 如果直接暴力遍历 就是O(n^2) -- 10^10

    // 另外一种暴力思想
    // 固定底得到最大高度 ---> 难搞
    // 固定高度得到最大底 --- > ok
    // 使用两边扩散
    // 遇到比i所在的高度小时， 停下
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxans = 0;
        for(int i = 0;i < n;++i)
        {
            int temp1 = i, temp2 = i+1;
            // 遇到边界就凉凉
            while(temp1 >= 0)
            {
                if(heights[temp1] < heights[i])
                {
                    // ++temp1;
                    break;
                }
                --temp1;
            }

            while(temp2 < n)
            {
                if(heights[temp2] < heights[i])
                {
                    // --temp2;
                    break;
                }
                ++temp2;
            }

            int ans = (temp2 - temp1-1) * heights[i];
            maxans = max(maxans, ans);
        }
        return maxans;
    }
};


class Solution1 {
public:
    // 使用空间换时间

    // 现在有 j0 < j1， 且height[j0] > height[j1]， 那么对于在j1后面的柱子， 就可以不用扩展了
    // 为什么要维护 单调栈这个数据结构
    // heights = [2,1,5,6,2,3] 
    // 对于这样一个数组
    // 2 这个高度能够扩展的区域已经被1堵死， 那么我们可以计算出2这个高度的矩形面积
    // 对于1这个高度， 我们可以往左， 可以往右扩展， 但是现在还没遍历到右边，所以搁置它， 那么要怎么搁置他
    // 5 ，对于5这个高度， 左边没法扩展， 但是右边还不知道， 所以搁置他
    // 6， 对于6这个高度， 仍然搁置
    // 遇到了2， 从现在开始，事情就变化了， 6 现在就可以确认 两边的高度都小于他，那么他的矩形面积就是本身
    // 对于5也是这样，他确认了他的扩展范围就只有 5 和 6， 同样能够计算矩形面积
    // 对于目前搁置的1， 还没有消息
    
    // 所以目前的想法， 就是把搁置的数放到单调栈中
    // 知道遇到出栈条件, 计算应有的宽度
    // 那么出栈结算的时候， 又要如何结算
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n), right(n);
        stack<int> stk;


        // 同时计算i节点对应的左边界和右边界
        for(int i=0;i<n;++i)
        {
            // 如果发现当前栈顶元素大于heights[i], 为了确定它的左边界， 将栈比该元素大的出栈。 得到左边界
            while(!stk.empty() && heights[stk.top()] >= heights[i])
            {
                stk.pop();
            }
            // 如果弹栈之后为空栈， 那么左边已经无人比他小了
            // 如果不是空栈， 那么就是栈的前一个元素， 也就是现在的栈顶元素(左边比原先栈顶小的元素)
            // 其中left[i] 存的是上一个节点的索引
            left[i] = (stk.empty() ? -1 : stk.top());
            stk.push(i);
        }

        stk = stack<int>();

        for(int i = n-1;i >= 0;--i)
        {
            while( !stk.empty() && heights[stk.top()] >= heights[i])
            {
                stk.pop();
            }
            right[i] = (stk.empty() ? n : stk.top());
            stk.push(i);
        }
        int ans = 0;
        for(int i = 0;i < n;++i)
        {
            ans = max(ans, (right[i]-left[i-1]-1)*heights[i]);
        }
        return ans;
    }

    int maxans;
};

// 常数级优化， 虽然上述解法直接得到了左边界， 但是要得到右边界， 其实由上述的
class Solution2 {
public:
    int largestRectangleArea(vector<int>& heights) {
        // 现在使用这个栈， 将高度存下来， 
        stack<pair<int, int>> stk;
        heights.push_back(-1);
        // 如果遇到栈顶元素比现有的元素小， 那么右边界就是i， 左边界是上一个元素
        for(int i = 0;i<heights.size();++i)
        {
            // 对于等于的情况怎么办
            // 如果仅仅这样写， 只能将一开始能够排除的给排除了
            while(!stk.empty() && stk.top().second > heights[i])
            {
                int height = stk.top().second;
                stk.pop();
                // 如果pop了之后没有值了
                int ans = height*(i-(stk.empty() ? -1 : stk.top().first)-1);
                maxans = max(ans, maxans);
            }
            stk.push(make_pair(i, heights[i]));
        }

        return maxans;
    }
    int maxans = 0;
};
int main()
{

    vector<int> vec = {2,4};
    Solution sl;
    // cout << vec.size() << endl;
    // cout << sl.largestRectangleArea(vec) << endl;
    Solution2 sl2;
    cout << sl2.largestRectangleArea(vec) << endl;
    

}