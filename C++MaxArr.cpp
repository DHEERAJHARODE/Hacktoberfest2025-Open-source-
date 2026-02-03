
#include<iostream>
using namespace std;
int main()
{
    int arr[5]={55,90,12,70,50},max=0,x;
    for(x=1; x<5; x++)
    {
        if(max<arr[x])
        {
            max = arr[x];
        }
    }
    cout<<"\nMaximum Number = "<<max;
return 0;
}
