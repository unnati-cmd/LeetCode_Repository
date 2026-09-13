class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if(s==''):
            return 0
        d = {}
        max_length = float("-inf")
        i = 0
        j = 0
        length = 0
        while j < len(s):
            d[s[j]] = d.get(s[j], 0) + 1
            length += 1
            while d.get(s[j]) > 1:
                d[s[i]] = d.get(s[i]) - 1
                i += 1
                length -= 1
            j += 1
            max_length = max(length, max_length)
        return max_length
