from collections import Counter

class Solution(object):
    def maxOperations(self, nums, k):
        counts = Counter(nums)
        ops = 0
        
        for num in list(counts.keys()):
            target = k - num
            
            if target in counts:
                if num == target:
                    ops += counts[num] // 2
                elif num < target: 
                    pairs = min(counts[num], counts[target])
                    ops += pairs
                    
        return ops