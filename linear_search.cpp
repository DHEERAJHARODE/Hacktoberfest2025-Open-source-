#include<bits/stdc++.h>
using namespace std;
int linearsearch(int arr[],int n,int key)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]==key)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    int n,k;
    cout<<"Enter the size of the array"<<endl;;
    cin>>n;
    int arr[n];
    cout<<"Enter the array elements"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter the element to be searched"<<endl;
    cin>>k;
    int pos=linearsearch(arr,n,k);
    if(pos==-1)
    {
        cout<<"Element not found"<<endl;
    }
    else
    {
        cout<<"Element found at index"<<" "<<pos<<endl;
    }
    return 0;
}