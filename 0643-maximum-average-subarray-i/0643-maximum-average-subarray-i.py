class Solution(object):
    def findMaxAverage(self, nums, k):
        n = len(nums)
        j, s = 0, 0
        for i in range(k):
            s += nums[i]

        max_avg = float(s)/k 
        for i in range(k, n):
            s = s - nums[j] + nums[i]
            j += 1
            if max_avg < float(s)/k:
                max_avg = float(s)/k
        return max_avg
            