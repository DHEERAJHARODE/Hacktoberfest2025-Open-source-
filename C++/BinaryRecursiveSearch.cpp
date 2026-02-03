#include <iostream>
using namespace std;


int BinarySearch(int arr[], int num, int low, int high){
 int mid;
 
 if (low > high){
  
  cout << "Number is not found";
  return 0;
  
 } else {
  
  mid = (low + high) / 2;
  
  if(arr[mid] == num){
   
   cout << "Number is found at " << mid << " index \n";
   return 0;
  
  } else if (num > arr[mid]) {
   
   BinarySearch (arr, num, mid+1, high);
   
  } else if (num < arr[mid]) {
   
   BinarySearch (arr, num, low , mid-1);
  }
 }
 
 
}
 
int main() {
 
 int num, i, n, low, high;
 
 cout <<"Enter the size of an array: ";
 cin >> n;
 int arr[n];
 
 
 for(i=0; i<n; i++) {
  cout <<"Enter the sorted value: ";
  cin >> arr[i];
 }
 
 cout <<"Enter a value to be search: ";
 cin >> num;
 
 low = 0;
 high = n-1;
 
 BinarySearch (arr, num, low, high);
 
 return 0;
}
