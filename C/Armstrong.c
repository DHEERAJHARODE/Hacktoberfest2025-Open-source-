#include<stdio.h>
#include<math.h>
int main() {
int n,d=0,r,s=0,t;
printf("Enter a no- ");
scanf("%d",&n);
t=n;
while (n>0)
{
  n=n/10;
  d=d+1;
} n=t;
while (n>0)
{
   r=n%10;
   printf("%d", d);
   s=s+pow(r,d);
   n=n/10;
} n=t;
if (n==s)
{
    printf("in %d is Armstrong",n);
} else
    printf("in %d is not Armstrong",n);
}