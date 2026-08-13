class Solution(object):
    def maxOperations(self, nums, k):
        nums.sort()
        left, right = 0, len(nums) - 1
        ops = 0
        
        while left < right:
            current_sum = nums[left] + nums[right]
            if current_sum == k:
                ops += 1
                left += 1
                right -= 1
            elif current_sum < k:
                left += 1
            else:
                right -= 1
                
        return ops