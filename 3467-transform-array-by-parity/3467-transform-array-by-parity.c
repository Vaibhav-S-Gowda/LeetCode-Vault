/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* transformArray(int* nums, int numsSize, int* returnSize) {
    int evenCount = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i]%2 == 0) evenCount++;
    }

    for (int i = 0; i < numsSize; i++) {
        if (i < evenCount) nums[i] = 0;
        else nums[i] = 1;
    }

    *returnSize = numsSize;

    return nums;
}