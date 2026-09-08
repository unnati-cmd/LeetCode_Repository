class Solution:
    def countCommas(self, n: int) -> int:
        length = ceil(math.log(n,10))
        if(n == 1000):
            return 1
        if(length<4):
            return 0
        count = 0
        for i in range(n,999,-1):
            length = math.log(n,10) + 1
            if(length<4):
                count += 0
                break
            divisions = ceil(length / 3)
            if(length>=4):
                count += (divisions-1)
        return count