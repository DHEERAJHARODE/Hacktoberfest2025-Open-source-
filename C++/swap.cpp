#include <iostream>
#include<math.h>
using namespace std;

void printarray(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }cout<<endl;

}

void swapalternate(int arr[],int size)
{
    for(int i=0;i<size;i+=2)
    {
        if(i+1<size)
        {
            swap(arr[i],arr[i+1]);
        }
    }
}

int main()
{
    int even[8]={4,5,2,3,6,7,8,9};
    int odd[5]={1,4,2,3,5};
    
    swapalternate(even , 8);
    printarray(even,8);

    cout<<endl;

    swapalternate(odd,5);
    printarray(odd,5);

return 0;
}