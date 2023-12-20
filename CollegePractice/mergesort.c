#include <stdio.h>

void merge(int arr[], int low, int mid, int high) {
  int n1 = mid - low + 1;
  int n2 = high - mid;

  // Create temporary arrays
  int left[n1], right[n2];

  // Copy data to temporary arrays
  for (int i = 0; i < n1; i++) {
    left[i] = arr[low + i];
  }
  for (int j = 0; j < n2; j++) {
    right[j] = arr[mid + 1 + j];
  }

  // Merge the temporary arrays back into arr[]
  int i = 0, j = 0, k = low;
  while (i < n1 && j < n2) {
    if (left[i] <= right[j]) {
      arr[k] = left[i];
      i++;
    } else {
      arr[k] = right[j];
      j++;
    }
    k++;
  }

  // Copy the remaining elements
  while (i < n1) {
    arr[k] = left[i];
    i++;
    k++;
  }
  while (j < n2) {
    arr[k] = right[j];
    j++;
    k++;
  }
}

void mergeSort(int arr[], int low, int high) {
  if (low < high) {
    // Find the middle point
    int mid = low + (high - low) / 2;

    // Sort first and second halves
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);

    // Merge the sorted halves
    merge(arr, low, mid, high);
  }
}

void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main() {
  int arr[] = {6, 5, 3, 1, 8, 7, 2, 4};
  int n = sizeof(arr) / sizeof(arr[0]);

  printf("Unsorted array: ");
  printArray(arr, n);

  mergeSort(arr, 0, n - 1);

  printf("Sorted array: ");
  printArray(arr, n);

  return 0;
}
