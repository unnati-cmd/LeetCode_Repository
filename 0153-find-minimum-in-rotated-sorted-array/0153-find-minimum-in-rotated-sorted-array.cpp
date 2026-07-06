class Solution {
public:
    int findMin(vector<int>& nums) {
        int j = nums[0];
        for(int i:nums){
            j = min(j,i);
        }
        return j;
    }
};