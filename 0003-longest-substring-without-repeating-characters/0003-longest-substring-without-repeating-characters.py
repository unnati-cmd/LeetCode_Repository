class Solution(object):
    def lengthOfLongestSubstring(self, s):
        i = 0
        j = i
        d = {}
        length = 0
        while(j<len(s)):
            d[s[j]] = d.get(s[j],0)+1
            while(d.get(s[j])>1):
                d[s[i]] -= 1
                if(d.get(s[i])==0):
                    del d[s[i]]
                i+=1
            length = max(length, len(d))
            j+=1
        return length

        