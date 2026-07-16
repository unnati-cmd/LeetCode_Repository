class Solution {
public:
    int mySqrt(int x) {
        long long low = 1, high = x;
        bool flag = false;
        while(low<=high){
            long long mid = low + abs(low-high)/2;
            if(mid*mid == x) {
                flag = true;
                return mid;
            }
            else if(mid*mid > x) high = mid - 1;
            else low = mid + 1;
        }
        if(!flag) return high;
        return 0;
    }
};