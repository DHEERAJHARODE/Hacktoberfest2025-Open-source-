#include <stdio.h>
int main()
{
    int n;
    printf("ENTER NUMBER OF ELEMENTS\n");
    scanf("%d", &n);
    int a[n];
    printf("ENTER THE NUMBERS");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    // finding the max
    int max = a[0];
    for (int i = 0; i < n; i++)
    {
        if (a[i] > max)
            max = a[i];
    }
    printf("maximum = %d", max);
    return 0;
}
