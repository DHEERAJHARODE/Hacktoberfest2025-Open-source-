#include<stdio.h>
int stack[100], choice, n, top, x, i;
void push(void);
void pop(void);
void display(void);
void stacktop(void);
int main()
{
    //clrscr();
    top=-1; 

    printf("Enter the size of STACK [MAX=100]:");
    scanf("%d", &n);

    printf("\n\t STACK OPERATIONS USING ARRAY:");

    printf("\n\t 1.PUSH\n\t 2.POP\n\t 3.STACKTOP\n\t 4.DISPLAY\n\t 5.EXIT");

    do
    {
        printf("\n\n Enter the Choice:");
        scanf("%d", &choice);

        switch(choice) 
        {
            case 1:
            {
                push();
                break;
            }
            case 2:
            {
                pop();
                break; 
            }
            case 3:
            {
                stacktop();
                break;
            }
            case 4: 
            {
                display();
                break;
            }
            case 5:
            {
                printf("\n\t EXIT ");
                break;
            }
            default:
            {
                printf ("\n\t Enter a Valid Choice (1/2/3/4/5)");
            }

        }
    }
    while(choice!=5);
    return 0;
}
void push()
{
    if(top>=n-1)
    {
        printf("\n\t STACK IS FULL.");

    }
    else
    {
        printf(" Enter Value:");
        scanf("%d", &x);
        top++;
        stack[top]=x;
    }
}
void pop()
{
    if(top<=-1)
    {
        printf("\n\t STACK IS EMPTY.");
    }
    else
    {
        printf("\n\t Popped element is: %d", stack[top]);
        top--;
    }
}
void stacktop()
{
    if(top<=-1)
    {
        printf("\n\t STACK IS EMPTY.");
    }
    else
    {
        printf("\n\t Top element is: %d", stack[top]);

    }
}

void display()
{
    if(top>=0)
    {
        printf("\n STACK: \n");
        for(i=top; i>=0; i--)
            printf("\n%d", stack[i]);

        printf("\n Next Choice:");
    }
    else
    {
        printf("\n STACK IS EMPTY.");
    }

}


