class Solution(object):

  def minCostClimbingStairs(self, cost):
    memo = {}

    def dp(i):
      if i >= len(cost):
        return 0

      # Return cached result if already computed
      if i in memo:
        return memo[i]

      # Recurrence relation: pay current cost + min of next 1 or 2 steps
      memo[i] = cost[i] + min(dp(i + 1), dp(i + 2))
      return memo[i]

    return min(dp(0), dp(1))