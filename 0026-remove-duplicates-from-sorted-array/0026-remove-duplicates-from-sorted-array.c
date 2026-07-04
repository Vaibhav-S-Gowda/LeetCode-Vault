int removeDuplicates(int* nums, int numsSize) {
    if (numsSize == 0) return 0;
    int i = 0, j = 0;

    while (j < numsSize) {
        if (nums[i] == nums[j]) {
            j++;
        } else {
            nums[++i] = nums[j];
        }
    }
    return i + 1;
}