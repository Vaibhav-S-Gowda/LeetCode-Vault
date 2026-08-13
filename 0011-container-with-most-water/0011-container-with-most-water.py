class Solution(object):
    def maxArea(self, height):
        i, j = 0, len(height) - 1
        maxi = 0

        while i < j:
            length = j - i
            if height[i] < height[j]:
                total = height[i]*length
                if maxi < total:
                    maxi = total
                i += 1
            else:
                total = height[j]*length
                if maxi < total:
                    maxi = total
                j -= 1
        return maxi