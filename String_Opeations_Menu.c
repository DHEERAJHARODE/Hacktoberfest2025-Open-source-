// By Malvericus (Malvika Bhadoriya)

#include<stdio.h>

int input();

int main()
{
    char str1[100], str2[100];
    printf("Enter a String: ");
    gets(str1);

    int choice;
    printf("~~~~~ String Operation Menu ~~~~~ \n");
    printf("1. Reverse of the String \n");
    printf("2. Check if the String is a Palindrome \n");
    printf("3. Compare the Strings \n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n");
    printf("Enter your choice: ");
    choice = input();
    
    switch(choice) {

        case 1:
        {
            int len;
            for (int i = 0; str1[i] != '\0'; i++)
            {
                len = i + 1;
            }
            
            for (int i = 0; str1[i] != '\0'; i++)
            {
                str2[i] = str1[(len-1) - i];
            }
            
            printf("The Reversed String is: \n");
            puts(str2);
            
            break;
        }

        case 2:
        {
            int len, condition = 0;
            for (int i = 0; str1[i] != '\0'; i++)
            {
                len = i + 1;
            }
            
            for (int i = 0; str1[i] != '\0'; i++)
            {
                str2[i] = str1[(len-1) - i];
            }

            for (int i = 0; str1[i] != '\0'; i++)
            {
                if (str1[i] == str2[i])
                {
                    condition = 1;
                    break;
                }                
            }

            if (condition)
            {
                printf("The String is a Palindrome \n");
            }

            else
            {
                printf("The String is NOT a Palindrome \n");
            }
            
            break;
        }

        case 3:
        {
            int condition = 0;
            
            printf("Enter Another String to Compare: ");
            getchar();
            gets(str2);

            for (int i = 0, j = 0; str1[i] != '\0' && str2[j] != '\0'; i++, j++)
            {
                if (str1[i] == str2[j])
                {
                    condition = 1;
                }

                else
                {
                    condition = 0;
                }
            }

            if (condition == 1)
            {
                printf("The 2 Strings are Equal \n");
            }

            else
            {
                printf("The 2 Strings are Unequal \n");
            }

            break;
        }

        default:
            printf("Enter a number from 1-3 ONLY! \n");
            
    }

    return 0;
}


int input() {
    int num;
    scanf("%d", &num);
    return num;
}
