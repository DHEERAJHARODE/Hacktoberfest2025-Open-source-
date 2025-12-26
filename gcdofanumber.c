#include <stdio.h>
void gcd(int num1, int num2);
int main()
{
    int x, y;
    printf("enter two numbers: ");
    scanf("%d%d", &x, &y);
    gcd(x, y);
    return 0;
}
void gcd(int num1, int num2)
{
    int i, GCD;
    for (i = 1; i <= num1 && i <= num2; i++)
        if (num1 % i == 0 && num2 % i == 0)
        {
            GCD = i;
        }
    printf("GCD of two numbers is %d", GCD);
}
