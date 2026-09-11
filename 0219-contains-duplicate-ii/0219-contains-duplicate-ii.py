class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        d = {}
        for i in range(len(nums)):
            if nums[i] not in d:
                d[nums[i]] = i
            else:
                prevIdx = d.get(nums[i])
                if(abs(prevIdx - i)<=k):
                    return True
                else:
                    d[nums[i]] = i
        return False