#include <iostream>  
using namespace std;  
  
int main ()  
{  
    int arr[50], num, temp, i, j;  
    cout << " Please, enter the total no. you want to enter: ";  
    cin >> num;  
      
    // use for loop to enter the numbers   
    for (i = 0; i < num; i++)  
    {  
        cout << " Enter the element " << i+1 << ": ";  
        cin >> arr[i];  
    }  
      
      
    for ( i = 0, j = num - 1; i < num/2; i++, j--)  
    {     
        temp = arr[i];  
        arr[i] = arr[j];  
        arr[j] = temp;  
    }  
    cout << "\n Reverse all elements of the array: " << endl;  
    // use for loop to print the reverse array  
    for ( i = 0; i < num; i++)  
    {  
        cout << arr[i] << " ";  
    }  
    return 0;  
}  
