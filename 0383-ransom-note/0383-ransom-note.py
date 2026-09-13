class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        l = list(magazine)
        for i in ransomNote:
            if(i in l):
                l.remove(i)
            else:
                return False
        return True