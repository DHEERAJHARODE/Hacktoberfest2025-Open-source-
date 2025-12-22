/* Which is Armstrong number?
A number thought of as an Armstrong Number if the sum of its own digits raised to the power number of digits gives the number itself . For example 0, 1, 153, 370, 371 and 407 are the Armstrong numbers.*/

#include<stdio.h>

#include <stdio.h>

int main() {
	

    int num, rem , sum = 0, originalnum , multi , i;
    int numofdigit=0 ;
    
    printf("Enter number : ");
    
    scanf(" %d", &num);
    
    originalnum = num ;
    
    while( num != 0)
    {
        num  %= 10;
        
        numofdigit++;
        
    }
    
    num = originalnum ;
    
    while( num != 0)
    {    
        multi = 1;
        i=0;
        
        rem = num % 10 ;
        
        while(i < numofdigit)
        {
            multi *= rem;
            i++;
        }
        
        sum += multi;
        num = num/10 ;
        
    }
    
    if( originalnum == sum)
        printf( " it's a armstong number.\n ");
    else
        printf( " it's not armstrong number.\n");
         
         return 0;
         
}
