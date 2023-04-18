class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        result = 0
        lowest = 0
        
        for now in range(1, len(prices)):
            if prices[now] < prices[lowest]:
                lowest = now
            result = max(result, prices[now] - prices[lowest])
            
        return result