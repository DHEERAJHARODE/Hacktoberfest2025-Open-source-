 #include <stdio.h>
#include <string.h>

struct lib
{
    int acc;
    char title[20];
    char author[20];
    int price;
    int flag;
};
int main()
{
    int n;
    int i = 0;
    struct lib iitdh[10];
    int j;
    do
    {
        printf("1. Add\n2.Display info\n3.List books of a author\n4.Specific book with acc no.\n5.Count\n6.All books\n7.Exit");
        scanf("%d", &n);

        switch (n)
        {

        case 1:
        {
            i++;
            iitdh[i].acc = i;
            printf("Enter the name");
            scanf("%s", iitdh[i].title);
            printf("Enter author");
            scanf("%s", iitdh[i].author);
            printf("Enter price");
            scanf("%d", &iitdh[i].price);
            printf("Enter 1 if issued or 0 if not issued");
            scanf("%d", &iitdh[i].flag);
            break;
        }

        case 2:
        {
            printf("Enter the acc no");
            scanf("%d", &j);

            for (int k = 0; k <= i; k++)
            {
                if (k == j)
                {
                    printf("%d %s %s %d %d\n", iitdh[k].acc, iitdh[k].title, iitdh[k].author, iitdh[k].price, iitdh[k].flag);
                }
            }
            break;
        }

        case 3:
        {
            char arr[20];
            scanf("%s", arr);
            for (int k = 1; k <= i; k++)
            {
                if (strcmp(arr, iitdh[k].author) == 0)
                {
                    printf("%d %s %s %d %d\n", iitdh[k].acc, iitdh[k].title, iitdh[k].author, iitdh[k].price, iitdh[k].flag);
                }
            }
            break;
        }

        case 4:
        {
            int m;
            scanf("%d", &m);
            for (int k = 1; k <= i; k++)
            {
                if (m == k)
                {
                    printf("%s\n", iitdh[k].title);
                }
            }
            break;
        }

        case 5:
        {
            printf("%d", i);
            break;
        }

        case 6:
        {
            for (int k = 1; k <= i; k++)
            {

                printf(" %s \n", iitdh[k].title);
            }
            break;
        }

        case 7:
        {
            printf("Exiting...\n");
            break;
        }
        }
    } while (n != 7);
}
