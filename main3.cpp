#include <stdio.h>

int main()
{
    int nilai1;
    int nilai2;

    printf("Masukkan Nilai Awal: ");
    scanf("%d", &nilai1);

    printf("<----------------->\n");

    printf("Masukkan Nilai Akhir: ");
    scanf("%d", &nilai2);

    printf("<----------------->\n");

    int totalOdd = 0;
    int totalEven = 0;

    for (int i = nilai1; i <= nilai2; i++)
    {
        if (i % 2 == 0)
        {
            printf("Bilangan %d adalah genap \n", i);
            totalEven++;
        }
        else
        {
            printf("Bilangan %d adalah ganjil \n", i);
            totalOdd++;
        }
    }

    printf("Dalam rentang %d hingga %d, ada total %d bilangan genap dan %d bilangan ganjil.\n", nilai1, nilai2, totalEven, totalOdd);

    return 0;
}
