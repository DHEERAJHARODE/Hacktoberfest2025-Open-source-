#include <stdio.h>
void bubble_short(int arr[], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void print_arr(int arr[], int n){

    for (int i = 0; i < n; i++)
    {
        printf("%d  ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int i,j, n, arr[400];
    printf("Enter the no of elements you want to inshart - ");
    scanf("%d", &n);
    for (i = 0, j=1; i < n, j<=n; i++, j++)
    {
        printf("Enter the %d value ", j);
        scanf(" %d", &arr[i]);
    }
    printf("The unsorted Array: \n ");
    print_arr(arr, n); // Before swaping
    bubble_short(arr, n); // Swaping function
    print_arr(arr, n); //After swaping
    return 0;
}