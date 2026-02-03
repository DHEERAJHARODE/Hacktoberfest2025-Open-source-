#include<iostream.h>
#include<conio.h>
void main()
{
   clrscr();
   int sml=1, i, limit;
   char ch=sml;
   cout<<"How many smiley face you want to print ? ";
   cin>>limit;
   for(i=0; i<limit; i++)
   {
      cout<<ch<<" ";
   }
   getch();
}
