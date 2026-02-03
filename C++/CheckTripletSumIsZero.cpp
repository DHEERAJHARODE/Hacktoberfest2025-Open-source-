// C++ program  to check whether a triplet is present or not whose sum is zero.
#include <bits/stdc++.h>
using namespace std;

//  Find Triplets Function
bool findTriplets(int arr[], int n)
{ 
    sort(arr,arr+n);
        
    for(int i=0; i<n-2; i++)
    {
        int low = i+1, high = n-1;
        while(low<high)
        {
            if(arr[low]+arr[high] == -arr[i])
            {
                return 1;
            }
            else  if(arr[low]+arr[high] > -arr[i])
            {
              high--;
            }
            else
            {
              low++;
             }
        }
   }
        
    return 0;
}


// Driver code
int main()
{
  int n;
  cout<<"Enter the size of Array : "<<endl;
  cin>>n;

  int arr[n];
  cout<<"Enter the elements of Array : "<<endl;
  for(int i = 0; i < n; i++)
    cin>>arr[i];

  bool ans = findTriplets(arr, n);

  if(ans == 1)
  {
    cout<<"There exist a triplet whose sum is zero";
  }
  else
  {
    cout<<"There is no triplet whose sum is zero";
  }

  return 0;
}
