#include <stdio.h>
#include <string.h>

// Function prototypes
void bubbleSort(char arr[][50], int n);
int linearSearch(char arr[][50], int n, char target[]);
void printArray(char arr[][50], int size);
void printResult(int result, char target[]);

int main() {
    // Array of unsorted strings
    char arr[][50] = {"banana", "apple", "cherry", "mango", "orange", "grape"};
    int size = sizeof(arr) / sizeof(arr[0]);
    char target[50];

    // Display original array
    printf("Original Array:\n");
    printArray(arr, size);

    // Step 1: Sort the array alphabetically
    bubbleSort(arr, size);
    printf("\nSorted Array:\n");
    printArray(arr, size);

    // Step 2: Input the string to search
    printf("\nEnter the string to search: ");
    scanf("%s", target);

    // Step 3: Perform Linear Search
    int result = linearSearch(arr, size, target);

    // Step 4: Display the result
    printResult(result, target);

    return 0;
}

// Function to sort strings using Bubble Sort
void bubbleSort(char arr[][50], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(arr[j], arr[j + 1]) > 0) {
                // Swap the strings if they are in the wrong order
                char temp[50];
                strcpy(temp, arr[j]);
                strcpy(arr[j], arr[j + 1]);
                strcpy(arr[j + 1], temp);
            }
        }
    }
}
// Function to perform Linear Search
int linearSearch(char arr[][50], int n, char target[]) {
    for (int i = 0; i < n; i++) {
        if (strcmp(arr[i], target) == 0) {
            return i;  // Target found, return index
        }
    }
    return -1;  // Target not found
}

// Function to print the array of strings
void printArray(char arr[][50], int size) {
    for (int i = 0; i < size; i++) {
        printf("%s ", arr[i]);
    }
    printf("\n");
}

// Function to display the search result
void printResult(int result, char target[]) {
    if (result != -1)
        printf("String \"%s\" found at index %d.\n", target, result);
    else
        printf("String \"%s\" not found in the array.\n", target);
}

