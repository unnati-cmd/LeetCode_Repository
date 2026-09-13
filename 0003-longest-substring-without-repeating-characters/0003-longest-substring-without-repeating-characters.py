class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if(s==''):
            return 0
        max_length = float("-inf")
        i = 0
        j = 1
        length = 1
        while j < len(s):
            while s[j] in s[i:j]:
                i += 1
                length -= 1
            j += 1
            length += 1
            max_length = max(length, max_length)
        return max(max_length,length)
