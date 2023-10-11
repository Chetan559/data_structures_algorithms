#include <stdio.h>

int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key)
            return i; 
    }
    return -1; 
}

int main() {
    int size;
    printf("How many Elements do you want to add? ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter the Elements\n");
    for (int i = 0; i < size; i++) {
        printf("Enter %d Element ",i+1 );
        scanf("%d", &arr[i]);
    }
    int key, result;
    printf("Enter the element to search: ");
    scanf("%d", &key);
    result = linearSearch(arr, size, key);
    if (result == -1)
        printf("Element not found in the array.\n");
    else
        printf("Element found at index: %d\n", result);
    return 0;
}
