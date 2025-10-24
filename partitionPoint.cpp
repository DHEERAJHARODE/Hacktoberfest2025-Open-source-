// C++ program to find the element which is greater than
// left elements and smaller than right elements (or equal)
#include <bits/stdc++.h>
using namespace std;

int findElement(vector<int> &arr) {
    
    // Iteratte through each elements
    for(int i = 1; i < arr.size() - 1; i++) {

        // to store maximum in left
        int left = INT_MIN;
        for(int j = 0; j < i; j++) {
            left = max(left, arr[j]);
        }

        // to store minimum in right
        int right = INT_MAX;
        for(int j = i + 1; j < arr.size(); j++) {
            right = min(right, arr[j]);
        }

        // check if current element is greater
        // than left and smaller than right (or equal)
        if(arr[i] >= left && arr[i] <= right) {
            return arr[i];
        }

    }

    return -1;
}

int main() {
    vector<int> arr = {5, 1, 4, 3, 6, 8, 10, 7, 9};
    cout << findElement(arr);
    return 0;
}
