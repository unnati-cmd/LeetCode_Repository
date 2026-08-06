class Solution(object):
    def canAliceWin(self, nums):
        sum_single = 0
        sum_double = 0
        for i in nums:
            if(len(str(i))==1):
                sum_single += i
            else:
                sum_double += i
        if(sum_single == sum_double):
            return False
        return True
        