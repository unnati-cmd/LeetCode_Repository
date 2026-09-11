class Solution:
    def maxProfit(self, prices: List[int]) -> int:

        min_prof = []
        max_prof = []

        min_prof.append(prices[0])

        for i in range(1, len(prices)):
            min_prof.append(min(min_prof[i-1], prices[i]))

        max_prof = [0] * len(prices)
        max_prof[len(prices)-1] = prices[len(prices)-1]

        for i in range(len(prices)-2, -1, -1):
            max_prof[i] = max(max_prof[i+1], prices[i])

        profit = 0

        for i in range(len(prices)):
            profit = max(profit, max_prof[i] - min_prof[i])

        return profit