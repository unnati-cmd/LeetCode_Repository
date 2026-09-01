class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        map<int, int> mp;
        vector<int> v;
        int i = 0, j = 0;
        while (j < k) {
            mp[nums[j]]++;
            j++;
        }
        auto last = mp.rbegin();
        v.push_back(last->first);
        while (j < nums.size()) {
            mp[nums[i]]--;
            if (mp[nums[i]] == 0)
                mp.erase(nums[i]);
            mp[nums[j]]++;
            i++;
            j++;
            auto last = mp.rbegin();
            v.push_back(last->first);
        }
        return v;
    }
};