class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        if(len(s)!=len(t)):
            return false
        d = {}
        j = 0
        for i in s:
            if(i in d and d.get(i)!=t[j]):
                return False
            d[i] = t[j]
            j+=1
        d2={}
        j = 0
        for i in t:
            if(i in d2 and d2.get(i)!=s[j]):
                return False
            d2[i] = s[j]
            j+=1
        return True