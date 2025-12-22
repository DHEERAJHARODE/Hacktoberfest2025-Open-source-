#include<iostream>
using namespace std;

int linearSearch(int arr[],int n,int key){
    cin>>n;
    
    
  
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
    int n;
    int key;
    int arr[n];

     cin>>n;
       
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter the key"<<ends;
    cin>>key;
    cout<<linearSearch(arr,n,key);

    return 0;
}