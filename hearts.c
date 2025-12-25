// Program by Hadi

#include<stdio.h>
#include<math.h>
#include<string.h>

void print_top_half(double size, char ch) {
    for(double x=0;x<size;x++)
    {
        for(double y=0;y<=4*size;y++)
        {
            double dist1 = sqrt( pow(x-size,2) + pow(y-size,2) );
            double dist2 = sqrt( pow(x-size,2) + pow(y-3*size,2) );
            
            if (dist1 < size + 0.5 || dist2 < size + 0.5 ) {
                printf("%c", ch);
            }
            else
                printf(" ");
        }
        printf("\n");
    }
}

void print_bottom_half(double size, char ch, char* message, int print_line) {
    int message_length = strlen(message);
    if(message_length % 2 != 0)
        strcat(message, " ");
    
    for(double x=1;x<2*size;x++)
    {
        for(double y=0;y<x;y++)
            printf(" ");
        
        for (double y=0;y<4*size + 1 - 2*x; y++)
        {
            if (x>= print_line - 1 && x <= print_line + 1) {
                int idx = y - (4*size - 2*x - message_length) / 2;
                
                if(idx < message_length && idx >= 0) {
                    if (x == print_line)
                        printf("%c", message[idx]);
                    else 
                        printf(" ");
                }
                else
                    printf("%c", ch);
            }
            else
                printf("%c", ch);
        }
        printf("\n");
    }
}


/**
 * Prints a diamond shape with a message in the bottom half.
 * 
 * @param size The size of the diamond.
 * @param ch The character to use for the diamond.
 * @param message The message to print in the bottom half of the diamond.
 * @param print_line The line number at which to print the message.
 */


int main()
{
    double size=9;
    char ch=3;
    int print_line = 3;
    char message[] = " Happy Valentine's Day ";

    print_top_half(size, ch);
    print_bottom_half(size, ch, message, print_line);
    
    return 0;
}
