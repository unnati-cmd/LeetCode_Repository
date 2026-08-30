class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char, int> mp;
        int i = 0, j = 0, length = INT_MIN;
        while (j < s.size()) {
            mp[s[j]]++;
            while ((mp[s[j]] > 2) && i<j) {
                mp[s[i]]--;
                i++;
            }
            length = max(length, j - i + 1);
            j++;
        }
        return length;
    }
};