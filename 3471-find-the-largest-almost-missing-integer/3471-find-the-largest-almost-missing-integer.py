class Solution(object):
    def largestInteger(self, nums, k):
        freq = {}
        n = len(nums)
        
        for i in range(n - k + 1):
            subarray = nums[i : i + k]
            # Use set() to count each number at most ONCE per subarray
            for num in set(subarray):
                freq[num] = freq.get(num, 0) + 1
        
        # EXACTLY 1 subarray
        valid_nums = [num for num, count in freq.items() if count == 1]
        
        return max(valid_nums) if valid_nums else -1