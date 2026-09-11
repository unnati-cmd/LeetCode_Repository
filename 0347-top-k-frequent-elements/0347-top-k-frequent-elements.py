class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        d = {}
        l = []
        for i in nums:
            d[i]=d.get(i,0)+1
        new = list(dict(sorted(d.items(),key = lambda x: x[1],reverse = True)).keys())
        for i in range(k):
            l.append(new[i])
        return l