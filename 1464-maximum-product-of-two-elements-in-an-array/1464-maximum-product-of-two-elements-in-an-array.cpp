class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int i = 0, j = 1, maxi = INT_MIN;
        while(i<nums.size()){
            while(j<nums.size()){
                maxi = max(maxi,((nums[i]-1) * (nums[j]-1)));
                j++;
            } 
            i++;
            j = i+1;
        }
        return maxi;
    }
};