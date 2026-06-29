class Solution {
public:
    int longestConsecutive(vector<int>  & nums) {
        if(nums.size()==0) return 0;
        map<int,int>mp;
        for(int i:nums){
            mp[i]++;
        }
        int curr = 1;
        int longest = 1;
        auto it = mp.begin();
        auto nextIt = next(it);
        while(nextIt != mp.end()) {
            if(it->first + 1 == nextIt->first) {
                curr++;
            }
            else {
                longest = max(longest, curr);
                curr = 1;
            }
            it++;
            nextIt++;
        }
        longest = max(longest, curr);
        return longest;
    }
};