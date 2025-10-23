#include <iostream>
#include <vector>
using namespace std;

// Function to perform Fibonacci Search
int fibonacciSearch(const vector<int>& arr, int x) {
    int n = arr.size();

    // Initialize Fibonacci numbers
    int fibMMm2 = 0;      // (m-2)'th Fibonacci No.
    int fibMMm1 = 1;      // (m-1)'th Fibonacci No.
    int fibM = fibMMm2 + fibMMm1;  // m'th Fibonacci No.

    // fibM is the smallest Fibonacci number greater than or equal to n
    while (fibM < n) {
        fibMMm2 = fibMMm1;
        fibMMm1 = fibM;
        fibM = fibMMm2 + fibMMm1;
    }

    // Marks the eliminated range from front
    int offset = -1;

    // While there are elements to inspect
    while (fibM > 1) {
        // Check if fibMMm2 is a valid index
        int i = min(offset + fibMMm2, n - 1);

        if (arr[i] < x) {
            // Move 1 Fibonacci down
            fibM = fibMMm1;
            fibMMm1 = fibMMm2;
            fibMMm2 = fibM - fibMMm1;
            offset = i;
        }
        else if (arr[i] > x) {
            // Move 2 Fibonacci down
            fibM = fibMMm2;
            fibMMm1 = fibMMm1 - fibMMm2;
            fibMMm2 = fibM - fibMMm1;
        }
        else
            return i; // Element found
    }

    // Compare last element
    if (fibMMm1 && arr[offset + 1] == x)
        return offset + 1;

    // Not found
    return -1;
}

int main() {
    vector<int> arr = {1, 9, 18, 24, 27, 35, 38, 41, 49, 53, 55, 66, 67, 72, 75, 77, 81, 89, 90, 97};

    int key;
    char choice;

    do {
        cout << "\nEnter the element to be searched: ";
        cin >> key;

        int index = fibonacciSearch(arr, key);

        if (index >= 0)
            cout << "Element found at index: " << index << endl;
        else
            cout << "Element not found.\n";

        cout << "\nDo you want to search more (y/n)? ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    return 0;
}
