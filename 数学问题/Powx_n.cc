class Solution {
public:
    // 这道题应该归到 分治法里面去
    double myPow(double x, int n) {
        long long N = n;
        return n >=0 ? quickMul(x, N)  : quickMul(x, -N);

    }

    double quickMul(double x, long long N)
    {
        if(N == 0)
        {
            return 1.0;
        }
        double y = quickMul(x, N/2);
        return N%2 == 0 ? y*y: y*y*x;
    }
};