class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        int j = 0;
        for (int i = nums.front(); i <= nums.back(); i++) {
            if (j < nums.size() && nums[j] == i) {
                j++;            
            } else {
                ans.push_back(i);
            }
        }
        return ans;
    }
};