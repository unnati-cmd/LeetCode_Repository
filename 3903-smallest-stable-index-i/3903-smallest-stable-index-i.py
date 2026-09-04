class Solution:
    def firstStableIndex(self, nums: list[int], k: int) -> int:
        i = 0
        check = False
        min_idx = float('inf')
        while(i < len(nums)):
            diff = max(nums[0:i+1]) - min(nums[i:])
            if(diff <= k):
                return i              
            i+=1
        return -1