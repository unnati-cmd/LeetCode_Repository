class Solution:
    def missingMultiple(self, nums: List[int], k: int) -> int:
        i = 1
        while(i<=len(nums)):
            if i*k not in nums:
                return i*k
            i+=1
        return i*k
        