class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int sum = 0, j = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums.size() % (j++) == 0) {
                sum += (nums[i] * nums[i]);
            }
        }
        return sum;
    }
};