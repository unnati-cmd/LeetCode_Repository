class Solution:
    def numIdenticalPairs(self, nums: List[int]) -> int:
        d = {}
        sum = 0
        for i in nums:
            d[i] = d.get(i,0)+1
        for i,j in d.items():
            sum += ((j*(j-1))//2)
        return sum