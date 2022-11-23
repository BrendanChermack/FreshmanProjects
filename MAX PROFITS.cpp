class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        #first a selection of the lowest price
        #then compare it to the rest of the array past the selection made and see if profit is made if not return 0;\
        start = 0
        next = 1
        profit = 0
        while next < len(prices):
            cProfit = prices[next] - prices[start]
            if prices[start] < prices[next]:
                profit = max(cProfit,profit)
            else:
                start = next
            next+=1
        return profit
