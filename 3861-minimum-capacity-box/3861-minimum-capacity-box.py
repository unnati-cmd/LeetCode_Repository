class Solution:
    def minimumIndex(self, capacity: list[int], itemSize: int) -> int:
        l = 0
        mini = float('inf')
        for i in capacity:
            if(i>=itemSize):
                l+=1
                mini = min(mini,i)
        if(l):
            return capacity.index(mini)
        else:
            return -1