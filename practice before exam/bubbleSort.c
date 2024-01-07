// Online C compiler to run C program online
#include <stdio.h>

int main() {
    // Write C code here
     int arr[10]={5,9,8,3,4,6,2,7,1,11};
     int temp;
     for(int i=0;i<9;i++){
     for(int j=0;j<9-i;j++){
         if(arr[j]>arr[j+1]){
             temp=arr[j];
             arr[j]=arr[j+1];
             arr[j+1]=temp;
         }
     }
         
     }
     for(int i=0;i<10;i++){
         printf("%d  ",arr[i]);
     }
    return 0;
}