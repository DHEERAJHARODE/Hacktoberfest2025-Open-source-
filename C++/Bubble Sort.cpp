#include<iostream>
using namespace std;
//displaying sorted array
void display(int *array, int size) {
   for(int i = 0; i<size; i++)
      cout << array[i] << " ";
   cout << endl;
}

void bubbleSort(int arr[], int n){
    //base case
    if(n==0 || n==1)
    return ;

    for(int i=0; i<n-1; i++){
        if(arr[i]>arr[i+1]){
            swap(arr[i], arr[i+1]); //used swap function 
        }
    }

    bubbleSort(arr, n-1);
}

int main() {
   int n;
   cout << "Enter the number of elements: ";
   cin >> n;
   int arr[n];     //create an array with given number of elements
   cout << "Enter elements:" << endl;
   for(int i = 0; i<n; i++) {
      cin >> arr[i];
   }
   cout << "Array before Sorting: ";
   display(arr, n);
   bubbleSort(arr, n);
   cout << "Array after Sorting: ";
   display(arr, n);
}
