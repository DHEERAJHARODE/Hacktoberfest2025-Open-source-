#include<iostream>
using namespace std;

void reversetheArray(int arr[],int n)
{
    int start=0,end=n-1,temp;
    while(start<end)
    {
        temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        start++;
        end--;
    }
}
void printarray(int arr[],int n)
{
    cout<<"Array After Reversing"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<"\t";
    }
}
int main()
{
    int a[20],i,n;
    cout<<"Enter the number of elements in Array : ";
    cin>>n;
    cout<<"Enter "<<n<<" elements of Array"<<endl;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    reversetheArray(a,n);
    printarray(a,n);
    return 0;
}