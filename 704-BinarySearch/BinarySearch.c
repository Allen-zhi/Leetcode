#include <stdio.h>

// Function to perform binary search on a sorted array
int binary_search(int nums[], int n, int target) {
    int low = 0, high = n - 1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2; // This prevents overflow
        
        if (nums[mid] == target) {
            return mid; // Target found, return index
        } else if (nums[mid] < target) {
            low = mid + 1; // Target is in the upper half
        } else {
            high = mid - 1; // Target is in the lower half
        }
    }
    
    return -1; // Target not found
}

// Main function to test the binary search
int main() {
    int nums[] = {-1, 0, 3, 5, 9, 12}; // Example array
    int target = 9; // Example target
    int n = sizeof(nums) / sizeof(nums[0]); // Calculate number of elements in array
    
    int index = binary_search(nums, n, target);
    
    if (index != -1) {
        printf("Target %d found at index %d.\n", target, index);
    } else {
        printf("Target %d not found in the array.\n", target);
    }
    
    return 0;
}

