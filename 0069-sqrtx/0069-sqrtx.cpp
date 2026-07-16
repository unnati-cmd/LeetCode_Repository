class Solution {
public:
    int mySqrt(int x, int a = 1, int i = 0) {
        if(x<0) return i-1;
        if(x == 0) return i;
        return mySqrt(x-a, a+2, i + 1);
    }
};