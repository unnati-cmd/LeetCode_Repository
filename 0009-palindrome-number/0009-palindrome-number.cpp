class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        long long new_num = 0;
        long long old = x;
        while(x){
            new_num = new_num*10 + (x%10);
            x/=10;
        }
        if(old == new_num) return true;
        return false;
    }
};