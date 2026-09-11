class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        ans = nums[0]
        for i in nums[1:]:
            ans^=i
        return ans