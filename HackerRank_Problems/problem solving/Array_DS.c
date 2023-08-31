#include <stdio.h>

void reverseArray(int arr[], int N) {
    int k = 0;
    int l = N - 1;
    int temp; 

    while (k < l) {
        
        temp = arr[k];
        arr[k] = arr[l];
        arr[l] = temp;

        k++;
        l--;
    }
}

int main() {
    
    int N;
    
    scanf("%d",&N);
    
    int arr[N];
    
    
    for (int i = 0; i <= N; i++) {
        scanf("%d ", &arr[i]);
    }
    
    
    reverseArray(arr, N);
    
    for (int i = 0; i <= N-1; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
