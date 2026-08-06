class Solution(object):
    def findNumbers(self, nums):
        return len([i for i in nums if (math.floor(math.log10(i))+1)%2==0])
        