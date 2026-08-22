class Solution(object):
    def checkDivisibility(self, n):
        original_n = n
        digits = []

        while n > 0:
            digits.append(n%10)
            n //= 10
        
        digit_prod = 1
        for d in digits:
            digit_prod *= d

        total = sum(digits) + digit_prod

        return original_n % total == 0
        