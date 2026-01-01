#include<bits/stdc++.h>
using namespace std;
int search(int arr[],int n){
    int start = 0;
    int end = n-1;
    while(start<end){
        int mid = start + (end - start)/2;
        if(arr[mid]<arr[mid+1]){
            start = mid+1;
        }
        else{
            end = mid;
        }
        
    }return start;
}
int main(){
    int arr[10]={1,2,3,4,5,4,3,2,1,0};
    int elm = search(arr,10);
    cout<<"peak is : ";
    cout<<arr[elm];
}