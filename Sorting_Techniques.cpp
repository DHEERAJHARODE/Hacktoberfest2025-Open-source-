#include<iostream>
using namespace std;
void read(int a[],int n){
    cout<<"Enter Array Elements:";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
}
void print(int a[],int n){
    cout<<"Array Elements Are: ";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}
void swap(int *x,int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
}
void bubblesort(int a[],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                swap(a[j],a[j+1]);
            }
        }
    }
}
void insertionSort(int arr[],int size){
    int cur,prev;
    for(int i=1;i<size;i++){
        cur=arr[i];
        prev=i-1;
        while(prev>=0 && arr[prev]>cur){
            arr[prev+1]=arr[prev];
            prev--;
        }
        arr[prev+1]=cur;
    }
}
void SelectionSort(int ar[],int n){
    for(int i=0;i<n-1;i++){
        int minIndex=i;
        for(int j=i+1;j<n;j++){
            if(ar[j]<ar[minIndex])
            minIndex=j;
        }
        swap(ar[i],ar[minIndex]);
    }
}
int main()
{
    int n,ch;
    
    cout<<"Enter the size of array:- ";
    cin>>n;
    int ar[n];
    read(ar,n);
    cout<<"1.Bubble Sort\n2.Insertion Sort\n3.Selection Sort\nEnter Your Choice\n";
    cin>>ch;
    switch (ch){
        case 1:
            bubblesort(ar,n);
            print(ar,n);
        break;
        case 2:
            insertionSort(ar,n);
            print(ar,n);
        break;
        case 3:
            SelectionSort(ar,n);
            print(ar,n);
        break;
        default:
        cout<<"Wrong Choice!!!";
        break;
    }
    return 0;

}
