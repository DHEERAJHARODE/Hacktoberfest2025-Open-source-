#include <iostream>
using namespace std;


int getpivot(int arr[], int n)
{
    int s=0;
    int e=n-1;
    int mid=s+(e-s)/2;

    while(s<e)
    {
        if(arr[mid]>=arr[0])
        {
            s=mid+1;
        }
        else{
            e=mid;
        }
        mid=s+(e-s)/2;
    }
return s;
}

int binarysearch(vector<int>& arr,int s,int e,int k)
{
    int s=0;
    int e=e;
    int mid =(s+e)/2;
    while(s<=e)
    {
        if(arr[mid]==k)
        {
            return mid;
        }

        // go to right side 
        if(k>arr[mid])
        {
            s=mid+1;
        }
        else{
                e=mid-1;
        }
        mid=(s+e)/2;
    }
    return -1;        
}

int findposition(vector<int>& arr,int n,int k)
{
    int pivot=getpivot(arr,n)
        // binary search on second line
        if(k>=arr[pivot]&&k<=arr[n-1])
        {
            return binarysearch(arr,pivot,n-1,k)
        }
        // binary search on first line
        else
        {
            return binarysearch(arr,0,pivot,k)
        }

}