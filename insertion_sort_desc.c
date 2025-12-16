#include <stdio.h>
#include <math.h>   

int main() 
{ 
    int n;
    printf("Number of elements: ");
    scanf("%d", &n);

    int arr[n], ele, j;

    printf("Enter array elements:\n");
    for (int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);

    for (int i = 1; i < n; ++i) { 
        ele = arr[i]; 
        j = i - 1; 
  
        while (j >= 0 && arr[j] < ele) { 
            arr[j + 1] = arr[j]; 
            j -= 1;
        }
        arr[j + 1] = ele; 
    }
  
    for (int i = 0; i < n; i++) 
        printf("%d ", arr[i]);  
    return 0; 
} 