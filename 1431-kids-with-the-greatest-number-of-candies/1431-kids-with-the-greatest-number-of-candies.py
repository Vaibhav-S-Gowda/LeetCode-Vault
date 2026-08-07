class Solution(object):
    def kidsWithCandies(self, candies, extraCandies):
        max_candies = max(candies)

        result = []
        for i in candies:
            if (i + extraCandies) >= max_candies:
                result.append(True)
            else:
                result.append(False)
        
        return result