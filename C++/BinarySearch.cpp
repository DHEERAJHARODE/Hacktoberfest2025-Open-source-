//Binary Search is a searching method that works for sorted arrays only.
//The time complexity of Binary Search is O(logn)

#include<bits/stdc++.h>
using namespace std;
int binarySearch(int arr[],int n,int target){
  int start = 0;
  int end = n-1;
  while(start<=end){
    int mid = start+(end-start)/2;
    if(target<arr[mid]){
      end = mid-1;
    }
    else if(target>arr[mid]){
      start = mid+1;
    }
    else{
      return mid;
    }
  }
  return -1;
}
int main(){
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  int target;
  cin>>target;
  int index = binarySearch(arr,n,target);
  cout<<"The index of the "<<target<<" is: "<<index<<endl;
  return 0;
}
