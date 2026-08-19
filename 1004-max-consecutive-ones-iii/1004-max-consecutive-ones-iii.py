class Solution(object):
    def longestOnes(self, nums, k):
        j = 0
        result = 0

        for i in range(len(nums)):
            if nums[i] == 0:
                k -= 1

            while k < 0:
                if nums[j] == 0:
                    k += 1
                j += 1

            result = max(result, i - j + 1)

        return result