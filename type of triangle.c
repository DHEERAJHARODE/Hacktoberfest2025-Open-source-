//check type of triangle(equilateral, isosceles, right angled, scalene)

#include<stdio.h>
#include<math.h>
int main()
{
    int a, b, c, l, sum;
    printf("Enter a: ");
    scanf("%d", &a);
    printf("Enter b: ");
    scanf("%d", &b);
    printf("Enter c: ");
    scanf("%d", &c);

    if(((a<0) || (b<0) || (c<0)) || ((a==0) || (b==0) || (c==0))){
        printf("ERROR!!! Enter +ve and >0 values only \n");
    }
    else{
    if((a==b) && (b==c))
    printf("Equilateral \n");
    else if((a==b) || (a==c) || (b==c))
    {
        printf("Isosceles \n");
    }
    else if(((a*a)+(b*b)==(c*c)) || ((a*a)+(c*c)==(b*b)) || ((b*b)+(c*c)==(a*a)))
    {
        printf("Right angled \n");

    }
    else if(((a*a)+(b*b)<(c*c)) || ((a*a)+(c*c)>(b*b)) || ((b*b)+(c*c)<(a*a)))
    {
        printf("Obtuse \n");
    }
    else if((a==b) && (b==c))
    printf("Equilateral \n");

    else
    printf("Scalene");
    }
}
