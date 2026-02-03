#include <stdio.h>
int n;
void printMatrix(int matrix[][n]);

void floydalgo(int graph[][n])
{   int matrix[n][n], i, j, k;
    for (i = 0; i < n; i++)
      for (j = 0; j < n; j++)
        matrix[i][j] = graph[i][j];
        for (k = 0; k < n; k++)
        {   for (i = 0; i < n; i++)
            {   for(j = 0; j < n; j++)
                {   if (matrix[i][k] + matrix[k][j] < matrix[i][j])
                        matrix[i][j] = matrix[i][k] + matrix[k][j];
                }
            }
        }
        printf("\n\nOutput: \n");
        printMatrix(matrix);
}

void printMatrix(int matrix[][n])
{   for (int i = 0; i < n; i++)
    {   for (int j = 0; j < n; j++)
        {    if (matrix[i][j] == 100000)
                  printf("%s", "INF");
             else
                  printf("%d", matrix[i][j]);
             printf("\t");
          }
          printf("\n");
    }
}
int main()
{   printf("Enter the size of square matrix:-");
    scanf("%d",&n);
    int graph[n][n];
    printf("Enter the elements (if you want to write infinity then write100000):-\n");
    for (int i = 0; i < n; i++)
    {   for (int j = 0; j < n; j++)
        {   
            scanf("%d",&graph[i][j]);
        }
    }
    floydalgo(graph);
    return 0;
}
