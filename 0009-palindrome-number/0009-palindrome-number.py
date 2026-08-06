class Solution(object):
    def isPalindrome(self, x):
        if(x<0):
            return False
        s = ""
        while(x):
            s+=str(x%10)
            x=x//10
        i = 0
        j = len(s)-1
        while(i<=j):
            if(s[i]!=s[j]):
                return False
            i+=1
            j-=1
        return True