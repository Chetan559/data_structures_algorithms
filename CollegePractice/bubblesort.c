#include <stdio.h>
#include <stdlib.h>
void *bubblesort(int *arr, int n)
{
int temp, flag = 0;
for (int i = 0; i < n; i++)
{
// printf("Working on the pass no:%d\n", i+1);
flag = 1;
for (int j = 0; j < n - i - 1; j++)
{
if (arr[j] > arr[j + 1])
{
temp = arr[j];
arr[j] = arr[j + 1];
arr[j + 1] = temp;
flag = 0;
}
}
if(flag)
{
return;
}
}
return arr;
}
void print(int *arr, int n)
{
for (int i = 0; i < n; i++)
{
printf("%d ", arr[i]);
}
printf("\n");
}
int main()
{
int arr[10] = {17, 34, 82, 2, 1, 90, 7, 35, 5, 21}, n = 10;
printf("The array given is:\n");
print(arr, n);
bubblesort(arr, n);
printf("The array after Bubble sort:\n");
print(arr, n);
return 0;
}