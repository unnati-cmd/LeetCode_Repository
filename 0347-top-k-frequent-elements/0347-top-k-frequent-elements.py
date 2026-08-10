class Solution(object):
    def topKFrequent(self, nums, k):
        dict ={}
        for i in nums:
            dict[i] = dict.get(i,0)+1
        d = sorted(dict, key = lambda x: dict[x], reverse=True)
        return d[:k]
        