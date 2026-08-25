class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        if (nums.size() < k)
            return -1;
        int maxi = -1;
        unordered_map<int, int> mp;
        int i = 0, j = k - 1;
        for (; j < nums.size();) {
            unordered_set<int> current;
            for (int z = i; z <= j; z++) {
                current.insert(nums[z]);
            }
            for (int x : current) {
                mp[x]++;
            }
            i++;
            j++;
        }
        for (auto i : mp) {
            if (i.second == 1)
                maxi = max(maxi,i.first);
        }
        return maxi;
    }
};