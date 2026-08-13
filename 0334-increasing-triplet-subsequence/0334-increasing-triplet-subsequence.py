class Solution(object):
    def increasingTriplet(self, nums):
        if len(set(nums)) < 3 :
            return False

        F_min = float('inf')
        S_min = float('inf')

        for i in nums:
            if i <= F_min:
                F_min = i
            elif i <= S_min:
                S_min = i
            else:
                return True
                
        return False