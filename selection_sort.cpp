#include <iostream>
#include <vector>
using namespace std;
//time complexity -> O(n^2)
void swap(vector<int>&arr, int i, int j){
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}
void selectionSort(vector<int>&arr){
  int n = arr.size();
  for(int i=0; i<n-1; i++){
    int minPos = i;
    for(int j=i+1; j<n; j++){
      if(arr[minPos] > arr[j]) minPos = j;
    }
    swap(arr, i, minPos);
  }
}
int main(){
  vector<int> nums = {0, 6, 7, 3, 5, 11, 36, 41, 22};
  cout<<"Array without Sorting: ";
  for(auto x: nums){
    cout<<x<<"";
  }cout<<endl;
  selectionSort(nums);
  cout<<"Array after selection Sort: ";
  for(auto x: nums){
    cout<<x<<"";
  }
}
