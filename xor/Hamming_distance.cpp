
class Solution {
public:
    int hammingDistance(int x, int y) {
        int s = x ^ y, ret = 0;
        while (s) {
            ret += s & 1;       //s&1 is the lowest bit to &, no all;
            s >>= 1;
        }
        return ret;
    }
};

int main(){
    Solution sl;
    sl.hammingDistance(1,4);
    
}