class Solution(object):
    def reverseWords(self, s):
        words = s.split()
        words = reversed(words)
            
        return " ".join(words)