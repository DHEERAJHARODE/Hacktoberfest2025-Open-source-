#include<iostream>
using namespace std;
int main()
{
    int num, rem, rev=0;
    cout<<"Enter the Number: ";
    cin>>num;
    while(num!=0)
    {
        rem = num%10;
        rev = rem + (rev*10);
        num = num/10;
    }
    cout<<"\nReverse = "<<rev;
    cout<<endl;
    return 0;
}