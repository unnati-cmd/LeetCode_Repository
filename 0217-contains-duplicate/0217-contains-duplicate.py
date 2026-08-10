class Solution(object):
    def containsDuplicate(self, nums):
        return not (len(nums) == len(set(nums)))
        