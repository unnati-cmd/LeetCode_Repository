class Solution:
    def reverseVowels(self, s: str) -> str:
        i = 0
        j = len(s)-1
        si = ''
        sj = ''
        while i<j:
            if(s[i].lower() not in ('a','e','i','o','u')):
                si += s[i]
                i+=1
            elif(s[j].lower() not in ('a','e','i','o','u')):
                sj += s[j]
                j-=1
            else:
                si += s[j]
                sj += s[i]
                i+=1
                j-=1
        if i==j:
            si += s[i]
        return si+sj[::-1]