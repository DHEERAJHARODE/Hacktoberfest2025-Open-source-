#include <stdio.h>  
  
int main(void) {  
  int n,m;  
  printf("Enter the number");  
  scanf("%d",&n);  
  m=2*n-1;  
  for(int i=1;i<=m;i++)  
  {  
    for(int j=1;j<=m;j++)  
    {  
       if(i==j || j==(m-i+1))  
       {  
         printf("*");  
       }  
       else  
       {  
         printf(" ");  
       }  
    }  
    printf("\n");  
  }  
  return 0;  
}  
