class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        i = 0
        j = k
        sumn = 0
        avg = float('-inf')
        while (i<k):
            sumn += nums[i]
            i+=1
        i = 0
        while(j<=len(nums)):
            avg = max(sumn/k,avg)
            sumn -= nums[i]
            i+=1
            if(j+1>len(nums)):
                break
            sumn += nums[j]
            j+=1
        return avg