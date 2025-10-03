#include <iostream>
using namespace std;

struct Student
{
    int rollNo;
    char name[15];
    float sgpa;
};//Student

void input(struct Student s[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<"Data of student no. "<<i+1<<endl;
        cout<<"\tEnter roll no. : ";
        cin>>s[i].rollNo;
        cout<<"\tEnter name : ";
        cin>>s[i].name;
        cout<<"\tEnter SGPA : ";
        cin>>s[i].sgpa;
       
    }//for    
}//input

void bubblesort(struct Student s[],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            if(s[j].rollNo>s[j+1].rollNo)
            {
                int temp=s[j].rollNo;
                s[j].rollNo=s[j+1].rollNo;
                s[j+1].rollNo=temp;
            }//if
        }//for j
    }//for i
   
    cout<<"List of Students sorted roll No wise using BUBBLE SORT : "<<endl;
   
    cout<<"|  Roll No   |       Name       |   SGPA   |"<<endl;
   
    for(int i=0;i<n;i++)
    {
        cout<<s[i].rollNo<<"\t|\t"<<s[i].name<<"\t|\t"<<s[i].sgpa<<endl;
    }//for
   
}//bubblesort

void quicksort(Student s[], int left, int right)
{
    if(left < right)
    {
        // Choose pivot (using the sgpa of the last element)
        float pivot = s[right].sgpa;
        int i = left - 1;

        for(int j = left; j < right; j++)
        {
            if(s[j].sgpa < pivot)
            {
                i++;
                // Swap entire Student structures
                Student temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }//if
        }//for
        // Final swap to place pivot in the correct position
        Student temp = s[i + 1];
        s[i + 1] = s[right];
        s[right] = temp;

        int pi = i + 1;

        // Recursively apply to sub-arrays
        quicksort(s, left, pi - 1);
        quicksort(s, pi + 1, right);
    }//if
}//quicksort

void linearSearch(int n,Student s[],float key)
{
    cout << "List of students with given SGPA:" << endl;
    for(int i=0;i<n;i++)
    {
       
        if(s[i].sgpa == key)
        {
           
            cout << "|  Roll No   |       Name       |   SGPA   |" << endl;
            cout << s[i].rollNo << "\t|\t" << s[i].name << "\t|\t" << s[i].sgpa << endl;
        }//if
       
    }//for
   
    cout<<"No entry with such SGPA";
   
}//linearSearch


int main()
{
    int n;
    cout<<"Enter no. of students whose data is to be entered : ";
    cin>>n;
 
    struct Student s[n];
   
    input(s,n);
   
    int choice;
   
    int left=0;
    int right=n-1;
   
    do
    {
        cout<<"**************MENU**************"<<endl;
        cout<<"1) Bubble Sort - Roll No. wise"<<endl;
        cout<<"2) Quick Sort - Top 10 Toppers"<<endl;
        cout<<"3) Linear Search - according to SGPA"<<endl;
        cout<<"4) EXIT "<<endl;
        cout<<"********************************"<<endl;
        cout<<"Enter your choice : "<<endl;
        cin>>choice;
   
        switch(choice)
        {
            case 1:
            bubblesort(s,n);
            break;
           
            case 2:
            quicksort(s,left,right);
           
            cout << "List of students sorted (Quick Sort) according to SGPA:" << endl;
            cout << "|  Roll No   |       Name       |   SGPA   |" << endl;
            for(int i = 0; i < n; i++)
            {
                cout << s[i].rollNo << "\t|\t" << s[i].name << "\t|\t" << s[i].sgpa << endl;
            }//for
            break;
           
            case 3:
            float key;
            cout<<"Enter SGPA to be searched : ";
            cin>>key;
   
            linearSearch(n,s,key);
            break;
           
            case 4:
            break;
           
            default:
            cout<<"Invalid Input";
            break;
           
        }//switch
       
    }//do
    while(choice!=4);
   
   

   
}//main
