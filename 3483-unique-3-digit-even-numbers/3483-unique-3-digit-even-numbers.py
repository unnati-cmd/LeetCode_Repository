class Solution:
    def totalNumbers(self, digits: List[int]) -> int:
        i = 0
        d = []
        for i in range (len(digits)):
            for j in range (len(digits)):
                for k in range (len(digits)):
                    if(i==j or j==k or i==k):
                        continue
                    if(digits[i] == 0):
                        continue
                    s1 = str(digits[i]) + str(digits[j]) + str(digits[k])
                    if int(s1) not in d and int(s1) % 2 == 0:
                        d.append(int(s1))
        return len(d)
