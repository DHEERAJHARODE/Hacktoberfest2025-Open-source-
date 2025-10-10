#include <iostream>
using namespace std;

// Bubble Sort Function
void bubbleSort(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]) { // Swap if element is greater
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Calling Bubble Sort
    bubbleSort(arr, n);

    // Output Sorted Array
    cout << "Sorted Array (Bubble Sort): ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
