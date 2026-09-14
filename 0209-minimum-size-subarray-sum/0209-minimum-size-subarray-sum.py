class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        i = 0
        j = 0
        sum = 0
        length = float('inf')
        l = 0
        while(j<len(nums)):
            sum += nums[j]
            while(sum>=target):
                length = min(length,j-i+1)
                sum-=nums[i]
                i+=1
                l-=1
            j+=1
        if(length!=float('inf')):
            return length
        return 0