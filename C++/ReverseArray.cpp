#include <iostream>
using namespace std;

int main()
{

    int n,i,j;
    cout << ("Enter Size of Array ");
    cin >> n;

    cout << ("Enter Elements ");
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    // reversing the Array
    
    i=0,j=n-1;
    
    while(i<j){
      swap(arr[i],arr[j]);
      i++;
      j--;
    }
    

    cout << ("The Array After Reversing is ");

     
     for(i=0;i<n;i++)
     cout<<arr[i]<<" ";
   
   

    return 0;
}
