class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> lastIndex; 
        for (int i = 0; i < (int)nums.size(); ++i) {
            auto it = lastIndex.find(nums[i]);
            if (it != lastIndex.end()) {
                if (i - it->second <= k) return true;
            }
            lastIndex[nums[i]] = i;
        }
        return false;
    }
};