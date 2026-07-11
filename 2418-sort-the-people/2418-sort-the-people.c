#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)b - *(int*)a);
}

char** sortPeople(char** names, int namesSize, int* heights, int heightsSize, int* returnSize) {
    *returnSize = namesSize;
    
    char** heightToName = (char**)calloc(100001, sizeof(char*));
    
    for (int i = 0; i < namesSize; i++) {
        heightToName[heights[i]] = names[i];
    }
    
    qsort(heights, heightsSize, sizeof(int), compare);
    
    char** result = (char**)malloc(namesSize * sizeof(char*));
    for (int i = 0; i < heightsSize; i++) {
        result[i] = heightToName[heights[i]];
    }
    
    free(heightToName);
    
    return result;
}