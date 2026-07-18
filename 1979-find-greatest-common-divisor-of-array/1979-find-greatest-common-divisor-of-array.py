class Solution(object):
    def findGCD(self, nums):
        minimum = min(nums)
        maximum = max(nums)
        gcd = 0
        for i in range(1,minimum + 1):
            min_value = minimum/i
            max_value = maximum/i

            if (min_value * i == minimum) & (max_value * i == maximum):
                gcd = i
        return gcd