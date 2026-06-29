#include <stdlib.h>

typedef struct {
    int val;
    int idx;
} Pair;

int compare(const void *a, const void *b) {
    Pair *p1 = (Pair *)a;
    Pair *p2 = (Pair *)b;
    return (p1->val > p2->val) - (p1->val < p2->val);
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    Pair *pairs = malloc(numsSize * sizeof(Pair));
    for (int i = 0; i < numsSize; i++) {
        pairs[i].val = nums[i];
        pairs[i].idx = i;
    }

    qsort(pairs, numsSize, sizeof(Pair), compare);

    int left = 0;
    int right = numsSize - 1;
    int *result = NULL;

    while (left < right) {
        long sum = (long)pairs[left].val + pairs[right].val; // Use long to prevent overflow
        if (sum == target) {
            result = malloc(2 * sizeof(int));
            result[0] = pairs[left].idx;
            result[1] = pairs[right].idx;
            *returnSize = 2;
            break; 
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }

    free(pairs);
    if (!result) *returnSize = 0;
    return result;
}