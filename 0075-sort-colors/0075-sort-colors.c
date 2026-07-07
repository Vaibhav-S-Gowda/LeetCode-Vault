void sortColors(int* nums, int numsSize) {
    int mid = 0, low = 0, high = numsSize - 1;
    int temp;

    while (mid <= high) {
        if (nums[mid] == 2) {
            temp = nums[mid];
            nums[mid] = nums[high];
            nums[high] = temp;
            high--;
        }
        else if (nums[mid] == 1) {
            mid++;
        }
        else {
            temp = nums[mid];
            nums[mid] = nums[low];
            nums[low] = temp;
            low++;
            mid++;
        }
    }
}