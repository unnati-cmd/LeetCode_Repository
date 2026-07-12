class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        nums.erase(unique(nums.begin(),nums.end()),nums.end());
        int i = 0;
        if(find(nums.begin(),nums.end(),1)==nums.end()) return 1;
        for(i = 0; i<nums.size()-1;i++){
            if(nums[i]>=0 && nums[i]+1 != nums[i+1]) return nums[i]+1;
        }
        return nums[i]+1;
    }
};