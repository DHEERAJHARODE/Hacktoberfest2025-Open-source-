#include<iostream>
using namespace std;
void swapping(int &a, int &b) {      //swap the content of a and b
   int temp;
   temp = a;
   a = b;
   b = temp;
}
//displaying sorted array
void display(int *array, int size) {
   for(int i = 0; i<size; i++)
      cout << array[i] << " ";
   cout << endl;
}
void bubbleSort(int *array, int size) {
   for(int i = 0; i<size; i++) {
      int swaps = 0;         //flag to detect any swap is there or not
      for(int j = 0; j<size-i-1; j++) {
         if(array[j] > array[j+1]) {       //when the current item is bigger than next
            swapping(array[j], array[j+1]);
            swaps = 1;    //set swap flag
         }
      }
      if(!swaps)
         break;       // No swap in this pass, so array is sorted
   }
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

// The up mentioned code can also be implemented using simple algo.
// The following code can be used to implement bubble sort.

/*#include<iostream>
using namespace std;

int main()
{
	int a,b,n;
	int m[5]={1,6,2,4,8};
	cout<<"Enter elements of unsorted array:"<<endl;
	for(int i=0; i<5; i++)
	{
		cin>>m[i];
	}
	
	for(a=0;a<5;a++)
	{
		for(b=a+1;b<5;b++)
		{
			if(m[a] > m[b])
			{
				n=m[a];
				m[a]=m[b];
				m[b]=n;
			}
			
		}
	}
	
	cout<<"Sorted array is :"<<endl;
	for(int i=0;i<5;i++)
	{
		cout<<m[i]<<endl;
	}
	return 0;
}*/
