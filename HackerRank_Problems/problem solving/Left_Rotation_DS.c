#include<stdio.h>

int main(){
    int d,n;
    
    scanf("%d %d",&n,&d);
    
    int arr[n];
    
    for(int i=0;i < n;i++){
        scanf("%d", &arr[i]);
    }
    
    
    d %= n; 
    
    int temp[d];
    
    for(int j=0;j < d;j++){
       temp[j] = arr[j];        
    }
    
    for(int i=0;i < n - d;i++){
        arr[i]= arr[i+d];
    }
    
    for(int j = n - d;j < n;j++){
        arr[j] = temp[j - ( n - d )];
    }   
        
    for(int i=0; i < n ;i++){
        printf("%d ",arr[i]);
    }
    
    
    return 0;
}
// the question is:-A left rotation operation on an array of size  shifts each of the array's elements  unit to the left. Given an integer, , rotate the array that many steps left and return the result.

// Example


// After  rotations, .

// Function Description

// Complete the rotateLeft function in the editor below.

// rotateLeft has the following parameters:

// int d: the amount to rotate by
// int arr[n]: the array to rotate
// Returns

// int[n]: the rotated array
// Input Format

// The first line contains two space-separated integers that denote , the number of integers, and , the number of left rotations to perform.
// The second line contains  space-separated integers that describe .

// Constraints

// Sample Input

// 5 4
// 1 2 3 4 5
// Sample Output

// 5 1 2 3 4
// Explanation

// To perform  left rotations, the array undergoes the following sequence of changes:

