class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        l = [1]
        for i in range(rowIndex):
            for j in range(i,0,-1):
                l[j] = l[j] + l[j-1]
            l.append(1)
        return l