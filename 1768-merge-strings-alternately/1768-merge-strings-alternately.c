

char * mergeAlternately(char * word1, char * word2){
    int i = 0, j = 0, count = 0, len = 0;
    char* mergedString = (char*)malloc(sizeof(char) * (strlen(word1) + strlen(word2) + 1));


    while ((i != strlen(word1)) && (j != strlen(word2))) {
        if (count == 0) {
            mergedString[len++] = word1[i++];
            count = 1;
        } else {
            mergedString[len++] = word2[j++];
            count = 0;
        }
    }

    while (i != strlen(word1)) {
        mergedString[len++] = word1[i++];
    }

    while (j != strlen(word2)) {
        mergedString[len++] = word2[j++];
    }

    // Add the null terminator at the end
    mergedString[len] = '\0';

    return mergedString;
}