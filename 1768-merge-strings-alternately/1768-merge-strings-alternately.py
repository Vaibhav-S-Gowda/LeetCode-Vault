class Solution(object):
    def mergeAlternately(self, word1, word2):
        i=0
        j=0
        new_string=""
        len_word1=len(word1)
        len_word2=len(word2)
        while(i<len_word1 and j<len_word2):
            new_string+=word1[i]+word2[j]
            i+=1
            j+=1
        new_string+=word1[i:]
        new_string+=word2[j:]
        return new_string