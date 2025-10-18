#include <iostream>
#include <vector>
#include <climits> // for INT_MIN
using namespace std;

int kadane(vector<int>& arr) {
    int maxSum = INT_MIN;
    int currentSum = 0;

    for (int i = 0; i < arr.size(); i++) {
        currentSum += arr[i];
        maxSum = max(maxSum, currentSum);

        if (currentSum < 0)
            currentSum = 0; // reset if sum goes negative
    }

    return maxSum;
}

int main() {
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    cout << "Maximum subarray sum is: " << kadane(arr) << endl;

    return 0;
}
