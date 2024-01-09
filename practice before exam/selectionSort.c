// Online C compiler to run C program online
#include <stdio.h>

int main() {
    // Write C code here
    int arr[10]= {5,8,56,4,3,2,7,9,6,1};
    int temp,min;
    
    for(int i=0;i<10;i++){
        min=i;
        for(int j=i;j<10;j++){
            if(arr[j]<arr[min]){
                temp=j;
                j=min;
                min=temp;
            }
        }
        if(min!=i){
            temp=arr[min];
            arr[min]=arr[i];
            arr[i]=temp;
        }
        
    }
    for(int i=0;i<10;i++){
        printf("%d  ",arr[i]);
    }
    return 0;
}