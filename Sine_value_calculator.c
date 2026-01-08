#include<stdio.h> 
#include<math.h> 
int main(void) 
{     
double sinValue,X;     
printf("please enter the value of calculate sine:");  
scanf("%lf",&X);     
sinValue=sin(X);     
printf("\n The sine value of %lf=%lf",X,sinValue);     
return 0; 
}