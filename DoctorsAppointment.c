/* Preprocessor Declaration */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

struct node //Declaration of structure NODE
{
    int serial;
    char name[100];
    char phone[12];
    struct node *next;
};

typedef struct node node;
int appointment=20;
node *head;

/* Functions Start */
void Appoint(node*pointer) //Function Declaration and Definition for Appointment Portal
{
    printf("\t\t\t*********Appointment Portal*********\n");
    int serial;
    char key;
    if(appointment==0)
    {
        printf("Sorry! Today's Appointment Full. Try after 8 P.M. for tomorrows appointment\n\n\n");
        printf("Press any key to continue...");
        scanf("%c",&key);
        if(key>=0)
        return;
    }
    else
    {
        if(pointer==NULL)
        {
            head=(node*)malloc(sizeof(node));
            pointer=head;
            pointer->next=NULL;
            printf("Enter your name: ");
        getchar();
        gets(pointer->name);
        phone_tag1:
        printf("Enter Mobile Number: ");
        gets(pointer->phone);
        int len=strlen(pointer->phone);
        if(len!=10)
        {
            printf("Invalid Mobile Number. Try again\n");
            goto phone_tag1;
        }
        int i;
        for(i=0;pointer->phone[i]!=NULL;i++)
        {
            if(pointer->phone[i]<'0' || pointer->phone[i]>'9')
            {
                 printf("Invalid Mobile Number. Try again\n");
                 goto phone_tag1;
            }
        }
        appointment--;
        serial=20-appointment;
        pointer->serial=serial;
        printf("\n\nAppointment accepted.\n");
        printf("Your serial number is %d.\n\n\n",pointer->serial);
        printf("Press any key to continue...");
        scanf("%c",&key);
        if(key>=0)
        return;
        }
        while(pointer->next!=NULL)
        {
            pointer=pointer->next;
        }

        pointer->next=(node*)malloc(sizeof(node));
        pointer=pointer->next;
        pointer->next=NULL;
        printf("Enter your name: ");
        getchar();
        gets(pointer->name);
        phone_tag:
        printf("Enter your Mobile Number: ");
        gets(pointer->phone);
        int len=strlen(pointer->phone);
        if(len!=10)
        {
            printf("Invalid Mobile Number. Try again\n");
            goto phone_tag;
        }
        appointment--;
        serial=20-appointment;
        pointer->serial=serial;
        printf("\n\nAppointment accepted.\n");
        printf("Your serial number is %d.\n\n\n",pointer->serial);
        printf("Press any key to continue...");
        scanf("%c",&key);
        if(key>=0)
        return;
    }
}

void Showlist(node *pointer) //Function Declaration and Definition to show appointment list.
{
    printf("\t\t\t*********Today's appointment list*********\n");
    if(pointer==NULL)
    {
        printf("No Appointment today!!!\n\n\n");
    }
    while(pointer!=NULL)
    {
        printf("%d: ",pointer->serial);
        printf("%s (Ph: %s )\n",pointer->name,pointer->phone);
        pointer=pointer->next;
    }
    printf("\n\n\n\nPress enter to go back to Doctor's menu: ");
    char key;
    getchar();
    scanf("%c",&key);
    if(key>=0)
    {
        return;
    }
}

/* Functions End */
int main()
{
        head=NULL;
        char query,query2;
        while(1)
    {
        printf("\t\t\t*********Main Menu*********\n");
        main_again:
            printf("1.I'm a Patient\n2.I'm the Doctor\n\n\n");
            scanf(" %c",&query);
            if(query=='1')
            {
                while(1)
                {
                    printf("\t\t\t*********Patient's Menu*********\n");
                    printf("1.Book Appointment\n2.Back to main menu.\n\n");
                    char appoint1;
                    patient_again:
                        scanf(" %c",&appoint1);
                        if(appoint1=='1')
                        {
                            Appoint(head);
                        }
                        else if(appoint1=='2')
                        {
                            break;
                        }
                        else
                        {
                            printf("Wrong Command!!!\n\n");
                            goto patient_again;
                        }
                }
            }
            else if(query=='2')
            {
                while(1)
                {
                    printf("\t\t\t*********Doctor's Menu*********\n");
                    printf("1.Show list\n2.Back to main menu.\n\n\n");
                    scanf(" %c",&query2);
                    if(query2=='1')
                    {
                        Showlist(head);
                    }
                    else if(query2=='2')
                    {
                        break;
                    }
                    else
                    {
                        printf("Wrong Command!!!\n\n");
                        continue;
                    }
                }
            }
            else if(query2=='2')
            {
                exit(0);
            }
            else
            {
                printf("Wrong Command!!!\n\n");
                goto main_again;
            }
    }
    return 0;
}
