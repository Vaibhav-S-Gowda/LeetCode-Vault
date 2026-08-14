class Solution(object):
    def maxVowels(self, s, k):
        vowels = set("aeiouAEIOU")
        n = len(s)
        sub_str = 0

        for i in range(k):
            if s[i] in vowels:
                sub_str += 1
                
        max_str = sub_str

        j = k
        while j < n:
            if s[j] in vowels:
                sub_str += 1
                
            if s[j - k] in vowels:
                sub_str -= 1
                
            if sub_str > max_str:
                max_str = sub_str
                
            j += 1
            
        return max_str