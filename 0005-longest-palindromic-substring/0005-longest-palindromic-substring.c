#include <string.h>
#include <stdlib.h>

int expandAroundCenter(char* s, int left, int right, int stringLength) {
    while(left >= 0 && right < stringLength && s[left] == s[right]) {
        left--;
        right++;
    }
    return right - left - 1;
}

char* longestPalindrome(char* s) {

    if (strlen(s) < 1) return "";
    int start = 0;
    int maxLength = 0;

    for(int i = 0; i < strlen(s); i++) {
        int len1 = expandAroundCenter(s, i, i, strlen(s));
        int len2 = expandAroundCenter(s, i, i + 1, strlen(s));

        int len = (len1 > len2) ? len1 : len2;

        if(len > maxLength) {
            maxLength = len;
            start = i - (len - 1) / 2;
        }
    }

    char* result = (char*)malloc((maxLength  + 1) * sizeof(char));
    strncpy(result, s + start, maxLength);
    result[maxLength] = '\0';

    return result;
}