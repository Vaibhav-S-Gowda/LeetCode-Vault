class Solution(object):
    def mergeAlternately(self, word1, word2):   
        i,j = 0, 0
        result = []
        while i < len(word1) and j < len(word2):
            if (i <= j):
                result.extend(word1[i])
                i = i + 1
            else:
                result.extend(word2[j])
                j = j + 1

        while i < len(word1):
            result.extend(word1[i])
            i = i + 1
        
        while j < len(word2):
            result.extend(word2[j])
            j = j + 1
        
        return "".join(result)