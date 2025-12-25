//Print a forward or backward star pattern with n lines.
//Author: Siddhant N.
#include<stdio.h>

void main()
{
    int ask;
    int star, line;
    int pattern;
    printf("How many lines do you want in pattern? : ");
    scanf("%d", &ask);
    printf("Press 1 for forward or 2 for backward pattern : ");
    scanf("%d", &pattern);

    if(pattern==1)
    {
        for (line=1; line<=ask; line++)
        {
            for(star = 1; star<=line; star++)
            {
            printf("*");
            }
        printf("\n");
        }

    }

    else if(pattern==2)
    {
        for (line=1; line<=ask; line++)
        {
            for(star = ask; star>=line; star--)
            {
            printf("*");
            }
        printf("\n");
        }
    }

    else
    {
        printf("Pattern not found.");
    }

}
