

#include<iostream>
using namespace std;
int main()
{
    int yr;
    cout<<"Enter the Year: ";
    cin>>yr;
    
   if(yr % 4 == 0)
   { 
       if(yr % 100 == 0)
       {
           if(yr % 400 == 0)
                cout << "It is a Leap year ";
           else
               cout <<"\nIt is not a Leap Year";            
       }
       else 
        cout << " It is a Leap Year ";
   }
    else
        cout << " It is not a leap year ";
    
    cout << endl;
    
    return 0;
}
