int pivotIndex(int* nums, int numsSize) {
    
    int sum = 0;
    int leftSum = 0;
    for(int i = 0; i < numsSize; i++) {
        sum += nums[i];
    }

    for(int i = 0; i < numsSize; i++) {
        int rightSum = sum - leftSum - nums[i];
        if(leftSum == rightSum) return i;
        leftSum += nums[i];
    }

    return -1;
}