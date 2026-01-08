#include <stdio.h>
#include <math.h>
long decimal_to_binary(int decimal_number)
{
long binary_number = 0;
int remainder, iteration = 1;

while (decimal_number != 0)
{
remainder = decimal_number%2;
decimal_number = decimal_number/ 2;
binary_number = binary_number+ remainder*iteration;
iteration = iteration*10;

}
return binary_number;
}

int main()
{

printf("Welcome to DataFlair tutorials!\n\n");

int decimal_number;
printf("Enter a positive integer in decimal system: ");
scanf("%d", &decimal_number);
printf("The number %d in decimal system to binary is %ld\n", decimal_number, decimal_to_binary(decimal_number));
return 0; //returning a value//
}
