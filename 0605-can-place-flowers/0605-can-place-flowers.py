class Solution(object):
    def canPlaceFlowers(self, flowerbed, n):
        length = len(flowerbed)
        count = 0

        for i in range(length):
            if flowerbed[i] == 0:
                left_empty = (i == 0) or (flowerbed[i-1] == 0)
                right_empty = (i == length - 1) or (flowerbed[i+1] == 0)

                if left_empty and right_empty:
                    flowerbed[i] = 1
                    count += 1
        return count >= n