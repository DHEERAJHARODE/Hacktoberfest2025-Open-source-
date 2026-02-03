// Increase the number of rows as possilbe and it will beautify the table for you...

#include <stdio.h>
#include <math.h>  //used log functions from this header
#include <string.h>   //header file for string functions

int main()
{
    long long x,y,i,j;  
    long long num,sq,max;

    printf("ROWS : ");     
    scanf("%lld",&i);     // Getting the input from the user 

    j = i;

    long long space = i>=j ? i : j;

    space = space*space;

    printf("\n");

    for( x=1;x<=i;x++)
    {
        for( y=1;y<=j;y++)
        {
            if(y==1) printf(" ");

            max = x>=y ? x : y;
            sq = max*max-(max-1);

            if(max==x)
            {
                if(x%2==0)
                {
                    num = sq+(x-y);
                }

                if(x%2!=0)
                {
                    num = sq-(x-y);
                }
            }

            if(max==y)
            {
                if(y%2!=0)
                {
                   num = sq+(y-x);
                }

                if(y%2==0)
                {
                    num = sq-(y-x);
                }
            }

            int num_space = log10(num);      // Algo to automate the spacing respective to the maximum element
            int space_space = log10(space);

            printf("%lld",num);

            for(int s=0;s<=(space_space-num_space);s++) { printf(" ");  }   

            }

            printf("\n");
        }
    return 0;
}
