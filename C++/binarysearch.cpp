#include <iostream>
using namespace std;

int binarysearch(int arr[],int size,int key)
{
    int start=0;
    int end=size-1;
    int mid =(start+end)/2;
    while(start<=end)
    {
        if(arr[mid]==key)
        {
            return mid;
        }

        // go to right side 
        if(key>arr[mid])
        {
            start=mid+1;
        }
        else{
                end=mid-1;
        }
        mid=(start+end)/2;
    }
    return -1;        
}

int main()
{
    int even[7]={2,3,4,6,5,7,8};
    int odd[6]={5,3,4,6,8,16};

    int evenindex=binarysearch(even,7,2);

    cout<<"index of 2 is "<<evenindex<<endl;

int oddindex=binarysearch(odd, 6, 8);
cout<<"index of 8 is "<<oddindex<<endl;
}