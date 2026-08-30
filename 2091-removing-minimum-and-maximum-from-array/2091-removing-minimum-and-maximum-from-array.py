class Solution:
    def minimumDeletions(self, nums: List[int]) -> int:
        if(len(nums)==1):
            return 1
        maximum = nums.index(max(nums))
        minimum = nums.index(min(nums))
        return min(min(len(nums) - maximum, maximum + 1) + min(len(nums) - minimum, minimum + 1),max(minimum, maximum) + 1,len(nums) - min(minimum, maximum))