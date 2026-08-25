class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0, product = 1;
        int temp = n;
        while (temp) {
            sum += (temp % 10);
            product *= (temp % 10);
            temp /= 10;
        }
        if ((n % (sum+product) == 0))
            return true;
        return false;
    }
};