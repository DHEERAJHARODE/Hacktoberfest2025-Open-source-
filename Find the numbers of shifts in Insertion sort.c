#include <stdio.h>
int main()
{
  int n,i,j,k,num,a[1000],c,key,flag=0;;
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    scanf("%d",&num);
    for(j=0;j<num;j++)
    {
     scanf("%d",&a[j]);
    }
    c=0;
    for(j=1;j<num;j++)
    {
      flag=0;
      key=a[j];
       k=j-1;
      while(k>=0 && a[k]>key)
      {
        a[k+1]=a[k];
        k=k-1;
      c++;
        flag=1;
      }
      if(flag==1)
      {
     a[k+1]=key;
       c++;
       }
     }
   
    printf("%d\n",c);
   
  }

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}

