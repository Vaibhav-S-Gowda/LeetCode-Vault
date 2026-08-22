class Solution(object):
    def checkDivisibility(self, n):
        sum1, product = 0, 1
        orig = n

        while n > 0:
            sum1 += n%10
            product *= n%10
            n //= 10

        if orig%(sum1+product) == 0:
            return True
        else : 
            return False