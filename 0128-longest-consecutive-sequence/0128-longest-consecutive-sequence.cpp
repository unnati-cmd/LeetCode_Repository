class Solution {
public:
    int longestConsecutive(vector<int>  & nums) {
        if(nums.size()==0) return 0;
        set<int>mp(nums.begin(),nums.end());
        int curr = 1;
        int longest = 1;
        auto it = mp.begin();
        auto nextIt= next(it);
        while(nextIt != mp.end()) {
            if(*it + 1 == *nextIt) {
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