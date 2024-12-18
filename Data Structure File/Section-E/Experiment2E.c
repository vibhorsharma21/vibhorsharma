#include <stdio.h>

// Function prototypes
void bubbleSort(int arr[], int n);
int binarySearch(int arr[], int size, int target);
void printArray(int arr[], int size);
void printResult(int result, int target);

int main() {
    // Input unsorted array
    int arr[] = {30, 12, 25, 8, 16, 2, 35, 20, 4};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target;

    printf("Original Array:\n");
    printArray(arr, size);

    // Step 1: Sort the array
    bubbleSort(arr, size);
    printf("\nSorted Array:\n");
    printArray(arr, size);

    // Step 2: Input the target number to search
    printf("\nEnter the number to search: ");
    scanf("%d", &target);

    // Step 3: Perform Binary Search
    int result = binarySearch(arr, size, target);

    // Step 4: Display the result
    printResult(result, target);

    return 0;
}

// Bubble Sort implementation
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Binary Search implementation
int binarySearch(int arr[], int size, int target) {
    int low = 0, high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
            return mid; // Target found, return index
        else if (arr[mid] < target)
            low = mid + 1; // Search right half
        else
            high = mid - 1; // Search left half
    }

    return -1; // Target not found
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to print the search result
void printResult(int result, int target) {
    if (result != -1)
        printf("Number %d found at index %d.\n", target, result);
    else
        printf("Number %d not found in the array.\n", target);
}
