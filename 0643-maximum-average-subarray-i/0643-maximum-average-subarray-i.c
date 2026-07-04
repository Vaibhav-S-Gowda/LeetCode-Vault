double findMaxAverage(int* nums, int numsSize, int k) {
    int sum = 0;
    
    for (int i = 0; i < k; i++) {
        sum += nums[i];
    }
    
    int max_sum = sum;
    
    for (int i = k; i < numsSize; i++) {
        sum += nums[i] - nums[i - k]; // Add incoming element, remove outgoing element
        if (sum > max_sum) {
            max_sum = sum;
        }
    }
    
    return (double)max_sum / k;
}