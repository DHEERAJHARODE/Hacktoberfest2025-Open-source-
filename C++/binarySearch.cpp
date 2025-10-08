#include <iostream>
#include <vector> // Required for using std::vector

// Function to perform binary search iteratively
int binarySearch(const std::vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2; // Calculate middle index efficiently

        if (arr[mid] == target) {
            return mid; // Target found, return its index
        } else if (arr[mid] < target) {
            low = mid + 1; // Target is in the right half
        } else {
            high = mid - 1; // Target is in the left half
        }
    }
    return -1; // Target not found
}

int main() {
    std::vector<int> sortedArray = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int targetValue = 23;

    int resultIndex = binarySearch(sortedArray, targetValue);

    if (resultIndex != -1) {
        std::cout << "Element " << targetValue << " found at index: " << resultIndex << std::endl;
    } else {
        std::cout << "Element " << targetValue << " not found in the array." << std::endl;
    }

    // Example with a value not present
    targetValue = 100;
    resultIndex = binarySearch(sortedArray, targetValue);
    if (resultIndex != -1) {
        std::cout << "Element " << targetValue << " found at index: " << resultIndex << std::endl;
    } else {
        std::cout << "Element " << targetValue << " not found in the array." << std::endl;
    }

    return 0;
}