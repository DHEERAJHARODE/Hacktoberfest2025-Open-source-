#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int target) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Check if the middle element is the target
        if (arr[mid] == target) {
            return mid; // Target found
        }

        // If the target is smaller than mid, search the left half
        if (arr[mid] > target) {
            high = mid - 1;
        }
        // If the target is larger than mid, search the right half
        else {
            low = mid + 1;
        }
    }

    return -1; // Target not found
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 10;

    int result = binarySearch(arr, n, target);
    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found in array." << endl;
    }

    return 0;
}
