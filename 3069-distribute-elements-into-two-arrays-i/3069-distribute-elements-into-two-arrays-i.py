class Solution(object):
    def resultArray(self, nums):
        arr1, arr2 = [nums[0]], [nums[1]]
        n = len(nums)
        for i in range(2, n):
            (arr1 if arr1[-1] > arr2[-1] else arr2).append(nums[i])
                
        return arr1 + arr2
