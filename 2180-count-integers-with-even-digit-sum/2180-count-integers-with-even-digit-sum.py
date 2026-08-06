class Solution:
    def digitCount(self,n):
        sum = 0
        while n > 0:
            sum += (n % 10)
            n = n // 10
        if sum % 2 ==0:
            return True
        else:
            return False

    def countEven(self, num: int) -> int:
        if num % 10 == 0:
            if self.digitCount(num):
                return (((num // 10) -1) * 5 + 4)+1
            else:
                return (((num // 10) -1) * 5 + 4)
        else:
            result = ((num // 10) -1) * 5 + 4
            start = (num // 10)*10
            end = num + 1
            for i in range(start,end):
                if self.digitCount(i):
                    result += 1
            return result