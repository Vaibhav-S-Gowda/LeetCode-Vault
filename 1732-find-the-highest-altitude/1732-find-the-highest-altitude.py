class Solution(object):
    def largestAltitude(self, gain):
        prefix_sum = 0
        heighest = 0

        for i in range(len(gain)):
            prefix_sum += gain[i]
            if heighest < prefix_sum:
                heighest = prefix_sum

        return heighest
