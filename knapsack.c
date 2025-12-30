#include<stdio.h>
#include<stdlib.h>

typedef struct knap
{
    float x[10]; //solution vectors
    float profit; //total profit
}node;

//Merging the sub arrays after sorting 
void merge (float *arr, int *low, int *mid, int *high)
{
    int i, j, k;
    float tempArr[100];
    
    i = *low;
    j = *mid + 1;
    k = *low;

    while (i <= *mid && j <= *high)
    {
        if (*(arr+i) > *(arr+j))
        {
            tempArr[k] = *(arr+i);
            i++;
        }
               
        else
        {
            tempArr[k] = *(arr+j);
            j++;
        }
      
        k++;
    }
    
    while (i <= *mid)
    {
        tempArr[k] = *(arr+i);
        
        i++;
        
        k++;
    }
    
    while (j <= *high)
    {
        tempArr[k] = *(arr+j);
        
        j++;
        
        k++;
    }
    
    for (int m = *low; m <= *high; m++)
        *(arr+m) = tempArr[m];
}

//Recursively calling the merge sort function to divide the array into smaller sub array then sorting each sub arrays 
void mergeSort (float *arr, int *low, int *high)
{
    int mid,temp;
    if (*low < *high)
    {
        mid = (*low + *high)/2;
        
        mergeSort (arr, low, &mid);
        temp = mid + 1;
        mergeSort (arr, &temp, high);
        
        //Function for individually sorting the sub arrays and then merging each sub arrays
        merge (arr, low, &mid, high);
    }  
}


int search(float *v,float key,int n)
{
  for(int i=0;i<n;i++)
  {
    if(key==*(v+i))
    {
      *(v+i) = -1;
      return i;
    }
  }
}

void copy_array(float *u,float *v,int *n)
{
  for(int i=0;i<*n;i++)
  {
    *(u+i) = *(v+i);
  }
}

void print(float *w,float *c,float *v,int *n)
{
  printf("\nweight of objects : ");
  for(int i=0;i<*n;i++)
  {
    printf("%0.2f ",*(w+i));
  }

  printf("\ncost of objects : ");
  for(int i=0;i<*n;i++)
  {
    printf("%0.2f ",*(c+i));
  }

  printf("\ncost per weight for each objects : ");
  for(int i=0;i<*n;i++)
  {
    printf("%0.2f ",*(v+i));
  }
}

node *knapsack(int *n,float *w,float *c,float *W)
{
  int low,high,i,index;
  float u[*n],v[*n];

  node *p = (node*)malloc(sizeof(node));

  for(i=0;i<*n;i++)
  {
    p->x[i] = 0;
    v[i] = *(c+i)/ *(w+i);
  }
  
  print(w,c,v,n);
  copy_array(u,v,n);
  low = 0;
  high = *n-1;
  mergeSort(u,&low,&high);

  i = 0;
  while((*W!=0)&&(i<*n))
  {
    index = search(v,u[i],*n);
    if(*W>=*(w+index))
    {
      p->x[index] = 1;
      *W = *W - p->x[index]*(*(w+index));
    }
    else
    {
      p->x[index] = *W/ *(w+index);
      *W = *W - p->x[index]*(*(w+index));
    }
    i = i + 1;
  }
  return p;
}

int main()
{
    float w[20], c[20], W; //w[i], and c[i] are weights, and cost, W is the knapsack capacity
    int n; //n is the number of objects
    node *q = NULL;
    printf("Enter the Number of Objects: ");
    scanf("%d", &n);
    printf("\n");
    for(int i = 0; i<n; i++)
    {
        printf("Enter the Weight of the object O[%d] ", i);
        printf("w[%d]= ",i);
        scanf("%f", &w[i]);
    }
    printf("\n");
    for(int i = 0; i<n; i++)
    {   
        printf("Enter the Cost of the object O[%d] ", i);
        printf("c[%d]= ",i);
        scanf("%f", &c[i]);
    }
    printf("\nEnter the capacity of knapsack: ");
    scanf("%f", &W);
    q = knapsack(&n, w, c, &W);
    for(int i=0;i<n;i++)
    {
        q->profit = q->profit + q->x[i]*c[i];
    }
    printf("\n\nThe solution vector is :-\n");
    for(int i = 0; i < n; i++)
    printf("x[%d]=%f\n", i, q->x[i]);
    printf("\nMaximum profit is: %f\n", q->profit);
    return(0);
}


