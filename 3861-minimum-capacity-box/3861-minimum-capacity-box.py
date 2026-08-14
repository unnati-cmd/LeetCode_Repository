class Solution:
    def minimumIndex(self, capacity: list[int], itemSize: int) -> int:
        l = []
        mini = float('inf')
        for i in capacity:
            if(i>=itemSize):
                l.append(capacity.index(i))
                mini = min(mini,i)
        if(len(l)):
            return capacity.index(mini)
        else:
            return -1