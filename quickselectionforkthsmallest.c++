# include<bits/stdc++.h>
using namespace std;
int partition (int arr[],int start,int end){
int x= arr[end];
int i=start;
for (int j=start;j<end;j++){
    if(arr[j]<=x){
        swap(arr[i],arr[j]);
        i++;
    }
}
swap(arr[i],arr[end]);
return i;
}
int quicksectionforkthelement(int arr[],int start,int end,int k){
if(k<=end-start+1){
  
    int idx=partition(arr,start,end);
if(idx-start==k-1){
return arr[idx];
}
if(idx-start>k-1){
return quicksectionforkthelement(arr,start,idx-1,k);
}
return quicksectionforkthelement(arr,idx+1,end,k-idx+start-1);
}
return INT_MAX;
}
int main(){
cout<<"enter the number of element in array n"<<endl;
int n;
cin>>n;
int arr[n];
cout<<"enter element"<<endl;
for(int i=0;i<n;i++){
    cin>>arr[i];

}
cout<<"enter kth smallest element to find "<<endl;
int k;
cin>>k;
cout<<quicksectionforkthelement(arr,0,n-1,k);

return 0;
}
