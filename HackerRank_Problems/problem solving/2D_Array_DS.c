#include<stdio.h>

int hourglass(int A[6][6]);

int main(){
    int i,j,n;
    int A[6][6];
    int answer;
    
    for(i=0;i<=5;i++){
        for(j=0;j<=5;j++){
            // scanf("%d",&A[i][j]);
            scanf("%d",&n);
            if(n<=9 && n>=-9){
                A[i][j] = n;
            }
            else {
                A[i][j] = 0;
                
            }
        }
    }
    answer = hourglass(A);
    printf("%d",answer);
    
}

int hourglass(int A[6][6]){
    int MaxSum= -63;
    int NewSum;
    
    for(int i=0;i<=3;i++){
        for(int j=0;j<=3;j++){
            NewSum =(A[i][j]+A[i][j+1]+A[i][j+2]+A[i+1][j+1]+A[i+2][j]+A[i+2][j+1]+A[i+2][j+2]);
        if (NewSum > MaxSum){
             MaxSum = NewSum; 
             }
        }
    }
    return MaxSum;
}

    

// the question:-
// An hourglass in  is a subset of values with indices falling in this pattern in 's graphical representation:

// a b c
//   d
// e f g
// There are  hourglasses in . An hourglass sum is the sum of an hourglass' values. Calculate the hourglass sum for every hourglass in , then print the maximum hourglass sum. The array will always be .

// Example


// -9 -9 -9  1 1 1 
//  0 -9  0  4 3 2
// -9 -9 -9  1 2 3
//  0  0  8  6 6 0
//  0  0  0 -2 0 0
//  0  0  1  2 4 0
// The  hourglass sums are:

// -63, -34, -9, 12, 
// -10,   0, 28, 23, 
// -27, -11, -2, 10, 
//   9,  17, 25, 18
// The highest hourglass sum is  from the hourglass beginning at row , column :

// 0 4 3
//   1
// 8 6 6
// Note: If you have already solved the Java domain's Java 2D Array challenge, you may wish to skip this challenge.

// Function Description

// Complete the function hourglassSum in the editor below.

// hourglassSum has the following parameter(s):

// int arr[6][6]: an array of integers
// Returns

// int: the maximum hourglass sum
// Input Format

// Each of the  lines of inputs  contains  space-separated integers .

// Constraints

// Output Format

// Print the largest (maximum) hourglass sum found in .