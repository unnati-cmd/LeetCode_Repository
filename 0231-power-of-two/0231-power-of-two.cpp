class Solution {
public:
    bool check(auto n){
        if((long long)n == n) return true;
        return false;
    }
    bool isPowerOfTwo(int n) {
        if(n==0) return false;
        if(n<0) return false;
        return check(log2(n));
    }
};