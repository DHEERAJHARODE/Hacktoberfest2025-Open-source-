#include<iostream>
using namespace std;
int main()
{
    int arr[100], tot, i, num, arrTemp[50], j=0, chk=0;
    cout<<"Enter the Size for Array Size: ";
    cin>>tot;
    cout<<"Enter "<<tot<<" Array Elements: ";
    for(i=0; i<tot; i++)
        cin>>arr[i];
    cout<<"\nEnter the Number to Search: ";
    cin>>num;
    for(i=0; i<tot; i++)
    {
        if(arr[i]==num)
        {
            arrTemp[j] = i;
            j++;
            chk++;
        }
    }
    if(chk>0)
    {
        cout<<"\nNumber Found at Index No. ";
        tot = chk;
        for(i=0; i<tot; i++)
            cout<<arrTemp[i]<<" ";
    }
    else
        cout<<"\nNumber doesn't Found!";
    cout<<endl;
    return 0;
}
