class Solution {
public:
    bool check(auto n){
        if((int)n == n) return true;
        return false;
    }
    bool isPowerOfFour(int n) {
        if(n<=0) return false;
        return check(log10(n)/log10(4));
    }
};