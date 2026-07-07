int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    
    int map[10001];
    memset(map, -1, sizeof(map));

    // Monotonic Stack implementation
    int* stack = (int*)malloc(nums2Size * sizeof(int));
    int top = -1;

    for (int i = 0; i < nums2Size; i++) {
        // While stack is not empty and current element is greater than stack's top element
        while (top >= 0 && nums2[i] > stack[top]) {
            map[stack[top]] = nums2[i]; // Map the next greater element
            top--;
        }
        stack[++top] = nums2[i];
    }
    free(stack);

    // Allocate memory for the result array
    int* result = (int*)malloc(nums1Size * sizeof(int));
    for (int i = 0; i< nums1Size; i++) {
        result[i] = map[nums1[i]];
    }

    *returnSize = nums1Size;
    return result;
}