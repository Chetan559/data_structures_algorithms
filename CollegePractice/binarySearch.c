#include <stdio.h>

int binarySearch(int arr[], int size, int key) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key)
            return mid; // Element found, return its index

        if (arr[mid] < key)
            left = mid + 1; // Search in the right half
        else
            right = mid - 1; // Search in the left half
    }

    return -1; // Element not found
}

int main() {
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter the sorted array elements:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    int key, result;

    printf("Enter the element to search: ");
    scanf("%d", &key);

    result = binarySearch(arr, size, key);

    if (result == -1)
        printf("Element not found in the array.\n");
    else
        printf("Element found at index: %d\n", result);

    return 0;
}
