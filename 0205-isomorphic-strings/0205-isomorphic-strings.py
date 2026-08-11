class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        if(len(s)!=len(t)):
            return False
        temp = ""
        d={}
        used = set()
        for i in range(len(s)):
            if(s[i] in d):
                if d[s[i]]!=t[i]:
                    return False
            else:
                if(t[i] in used):
                    return False
                d[s[i]] = t[i]
                used.add(t[i])
        for i in s:
            temp += d.get(i)
        if(temp == t):
            return True
        return False