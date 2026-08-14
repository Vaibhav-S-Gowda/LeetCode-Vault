class Solution(object):
    def tribonacci(self, n):
        if n == 0:
            return 0
        if n == 1 or n == 2:
            return 1
            
        dp = [0] * (n + 1)
        
        # Base values
        dp[0] = 0
        dp[1] = 1
        dp[2] = 1
        
        # Fill the DP table bottom-up
        for i in range(3, n + 1):
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3]
            
        return dp[n]