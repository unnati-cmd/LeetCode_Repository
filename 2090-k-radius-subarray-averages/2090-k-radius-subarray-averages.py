class Solution:
    def getAverages(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        if 2 * k + 1 > n:
            return [-1] * n
        avgs = [-1] * n
        sum = 0
        for x in range(2 * k + 1):
            sum += nums[x]
        i = 0
        j = 2 * k
        while True:
            avgs[i + k] = sum // (2 * k + 1)
            if j == n - 1:
                break
            sum -= nums[i]
            i += 1
            j += 1
            sum += nums[j]
        return avgs