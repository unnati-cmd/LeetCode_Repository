class Solution:
    def check_triangle(self,nums):
        if((nums[0] + nums[1] > nums[2]) and (nums[0] + nums[2] > nums[1]) and (nums[2] + nums[1] > nums[0])):
            return True
        return False

    def triangleType(self, nums: List[int]) -> str:
        if(len(nums)>3 or len(nums)<=0):
            return "None"
        if(nums[0] == nums[1] == nums[2]):
            return "equilateral"
        if(self.check_triangle(nums)):
            if(nums[0]==nums[1] or nums[0]==nums[2] or nums[2]==nums[1]):
                return "isosceles"
            else:
                return "scalene"
        else:
            return "none"