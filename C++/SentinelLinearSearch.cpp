#include <iostream>
#include <vector>
using namespace std;

// Function to search x in the given vector
int sentinelSearch(vector<int>& arr, int key) {
  
    // Last element of the vector
    int last = arr.back();

    // Element to be searched is placed at the last index
    arr.back() = key;
    int i = 0;
    while (arr[i] != key)
        i++;

    // Put the last element back
    arr.back() = last;

    // Return the index if found, otherwise return -1
    if ((i < arr.size() - 1) || (arr.back() == key))
        return i;
    else
        return -1;
}

int main() {
    vector<int> arr = { 10, 20, 180, 30, 60, 50, 110, 100, 70 };
    int key = 180;
    int result = sentinelSearch(arr, key);
    if (result != -1)
        cout << key << " is present at index " << result;
    else
        cout << "Element not found";

    return 0;
}
