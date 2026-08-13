class Solution(object):
    def isPalindrome(self, x):
        pal = str(x)
        rev = pal[::-1]
        if pal == rev:
            return True
        else:
            return False
        