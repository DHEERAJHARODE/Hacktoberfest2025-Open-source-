#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int linearSearch(const vector<int>& arr, int target) {
    for (size_t i = 0; i < arr.size(); ++i) {
        if (arr[i] == target)
            return i;  // Return the index where the target is found
    }
    return -1;  // Return -1 if the target is not found
}

int binarySearch(const vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;  // Return the index where the target is found

        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;  // Return -1 if the target is not found
}

int jumpSearch(const vector<int>& arr, int target) {
    int n = arr.size();
    int step = sqrt(n);
    int prev = 0;

    while (prev < n && arr[min(step, n) - 1] < target) {
        prev = step;
        step += sqrt(n);
        if (prev >= n)
            return -1;
    }

    while (arr[prev] < target) {
        prev++;
        if (prev == min(step, n))
            return -1;
    }

    if (arr[prev] == target)
        return prev;  // Return the index where the target is found

    return -1;  // Return -1 if the target is not found
}

int main() {
    vector<int> arr = {2, 3, 5, 8, 10, 12, 18, 20, 23, 27, 30, 35, 40};

    int target = 18;

    cout << "Array: ";
    for (int num : arr)
        cout << num << " ";
    cout << "\nTarget: " << target << "\n\n";

    int linearResult = linearSearch(arr, target);
    cout << "Linear Search Result: ";
    if (linearResult != -1)
        cout << "Found at index " << linearResult << "\n";
    else
        cout << "Not found\n";

    int binaryResult = binarySearch(arr, target);
    cout << "Binary Search Result: ";
    if (binaryResult != -1)
        cout << "Found at index " << binaryResult << "\n";
    else
        cout << "Not found\n";

    int jumpResult = jumpSearch(arr, target);
    cout << "Jump Search Result: ";
    if (jumpResult != -1)
        cout << "Found at index " << jumpResult << "\n";
    else
        cout << "Not found\n";

    return 0;
}
