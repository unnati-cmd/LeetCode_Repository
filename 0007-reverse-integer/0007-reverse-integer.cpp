class Solution {
public:
    int reverse(int a) {
        if (a == 0)
            return 0;
        long long new_num = 0;
        int x = llabs((long long)a);
        while (x % 10 == 0)
            x /= 10;
        while (x) {
            new_num = new_num * 10 + x % 10;
            x /= 10;
        }
        if (new_num > INT_MAX || new_num < INT_MIN) return 0;
        return (a >= 0) ? new_num : -new_num;
    }
};