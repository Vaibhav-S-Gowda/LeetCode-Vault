class Solution(object):
    def pivotIndex(self, nums):
        prefix_sum, suffix_sum = 0, sum(nums)
        n = len(nums)

        for i in range(n):
            suffix_sum -= nums[i]
            if suffix_sum == prefix_sum:
                return i
            prefix_sum += nums[i]
        
        return -1