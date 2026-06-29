class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        auto it = unique(nums.begin(),nums.end());
        if(it!=nums.end()) return true;
        return false;     
    }
};