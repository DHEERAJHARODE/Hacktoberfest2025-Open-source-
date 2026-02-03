#include <math.h>
#include <stdio.h>
 

void insertionSort(int arr[], int size)
{
    int i, key, j;
    for (i = 1; i < size; i++) {
        key = arr[i];
        j = i - 1;
 
        
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
int main()
{
   int size;
   printf("enter the size of array :");
   scanf("%d",&size);
   int arr[size];
   printf("Enter the array:");
   int i;
   for(i=0;i<size;i++){
   	scanf("%d",&arr[i]);
   }
    
    insertionSort(arr, size);
    printArray(arr, size);
 
    return 0;
}

     
      
