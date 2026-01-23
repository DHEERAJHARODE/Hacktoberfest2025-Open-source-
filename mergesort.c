#include<stdio.h>
void merge(int a[],int low,int mid,int high)
{
    int b[high];
    int i=low;
    int j=mid+1;
    int k=low;
    while(i<=mid && j<=high)
    {
        if(a[i]<=a[j])
        {
            b[k]=a[i];
            i++;
            k++;
        }
        else{
            b[k]=a[j];
            j++;
            k++;
        }
    }
    if(i>mid)
    {
        while(j<=high)
        {
            b[k]=a[j];
            j++;
            k++;
        }
    }
    else{
        while(i<=mid)
        {
            b[k]=a[i];
            i++;
            k++;
        }
    }
    for(k=low;k<=high;k++)
    {
        a[k]=b[k];
    }
}
void mergesort(int a[],int low,int high)
{
    if(low<high)
    {
        int mid=(low+high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,low,mid,high);
    }
}
int main()
{
   int n;
   printf("enter no.of elements\n");
   scanf("%d",&n);
   int a[n];
   for(int i=0;i<n;i++)
   {
      scanf("%d",&a[i]);
   }
   mergesort(a,0,n-1);
   for(int i=0;i<n;i++)
   {
      printf("%d\t",a[i]);
   }
}
