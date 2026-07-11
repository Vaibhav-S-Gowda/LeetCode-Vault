#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// **Struct**: pairs each person's name with their corresponding height
typedef struct {
    char* name;
    int height;
} Person;

// **Comparison function**: sorts the structural array in descending order
int compare(const void* a, const void* b) {
    Person* p1 = (Person*)a;
    Person* p2 = (Person*)b;
    return p2->height - p1->height; 
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** sortPeople(char** names, int namesSize, int* heights, int heightsSize, int* returnSize) {
    // **Memory allocation**: initialize the pair structures
    Person* people = (Person*)malloc(namesSize * sizeof(Person));
    for (int i = 0; i < namesSize; i++) {
        people[i].name = names[i];
        people[i].height = heights[i];
    }

    // **Sorting**: execute standard qsort built into C
    qsort(people, namesSize, sizeof(Person), compare);

    // **Output creation**: populate the resulting array with sorted strings
    char** result = (char**)malloc(namesSize * sizeof(char*));
    for (int i = 0; i < namesSize; i++) {
        result[i] = people[i].name;
    }

    free(people);
    *returnSize = namesSize;
    return result;
}