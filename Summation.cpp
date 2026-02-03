#include <iostream>

using namespace std;

int main(){

  int arr[]={2,3,4};
  int sum=0;
  
  for(int i=0;i<arr.size();i++)
    sum+=arr[i];
  
  cout<<sum<<endl;
  
  return 0;
}
