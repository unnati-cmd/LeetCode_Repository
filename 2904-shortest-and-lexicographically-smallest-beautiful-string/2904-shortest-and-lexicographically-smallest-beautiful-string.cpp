class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int i = 0;
        int ones = 0;
        int bestLen = INT_MAX;
        string ans = "";
        for (int j = 0; j < s.size(); j++) {
            if (s[j] == '1')
                ones++;
            while (ones > k) {
                if (s[i] == '1')
                    ones--;
                i++;
            }
            if (ones == k) {
                while (s[i] == '0')
                    i++;
                int len = j - i + 1;
                string curr = s.substr(i, len);
                if (len < bestLen) {
                    bestLen = len;
                    ans = curr;
                }
                else if (len == bestLen && curr < ans) {
                    ans = curr;
                }
            }
        }
        return ans;
    }
};