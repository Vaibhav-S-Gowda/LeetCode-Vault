int maxSubArray(int* nums, int numsSize) {
    int max = nums[0], sum = 0, i = 0;

    if (numsSize == 1) return max;
    while (i < numsSize) {
        sum += nums[i];
        if (sum > max) max = sum;
        if (sum < 0) sum = 0;
        i++;
    }
    return max;
}