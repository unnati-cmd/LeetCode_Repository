class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        d = {}
        j = 0
        for i in nums:
            d[i] = j
            j+=1
        while(j):
            if (target - nums[len(nums)-j]) in d and d[target - nums[len(nums)-j]]!=(len(nums)-j):
                return [len(nums)-j,d[target - nums[len(nums)-j]]]
            j-=1