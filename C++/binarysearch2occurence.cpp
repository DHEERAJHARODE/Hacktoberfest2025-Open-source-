#include <iostream>
using namespace std;

int firstocc(int arr[],int size,int key)
{
    int start=0;
    int end=size-1;
    int ans=-1;
    int mid =start + (end - start)/2;
    while(start<=end)
    {
        if(arr[mid]==key)
        {
            ans=mid;
            end=mid-1;;
        }
        else if(key>arr[mid])
        {
            start=mid+1;
        }
        else if(key<arr[mid])
        {
            end=mid-1;
        }
        
        mid=start + (end-start)/2;
    }
    return ans;        
}

int lastocc(int arr[],int size,int key)
{
    int start=0;
    int end=size-1;
    int ans=-1;
    int mid =start + (end - start)/2;
    while(start<=end)
    {
        if(arr[mid]==key) 
        {
            ans=mid;
            start=mid+1;;
        }
        else if(key>arr[mid])// move to right side
        {
            start=mid+1;
        }
        else if(key<arr[mid])// move to left side
        {
            end=mid-1;
        }
        
        mid=start + (end-start)/2;
    }
    return ans;        
}

int main()
{
    int even[6]={2,3,4,6,5,3};
    cout<<"First occurence of 3  is at index "<<firstocc(even , 6,3)<<endl;
    cout<<"last occurence of 3  is at index "<<lastocc(even , 6,3)<<endl;

 return 0;
}