#include <iostream>
#include <vector>

using namespace std;

int getSingle(vector<int>& arr) {
    int ans = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        ans = ans ^ arr[i];
    }
    return ans;
}

int main() {
    // Example usage
    vector<int> arr = {2, 3, 5, 4, 5, 3, 4}; // 2 appears once
    int singleElement = getSingle(arr);
    
    cout << "The element that appears once is: " << singleElement << endl;
    
    return 0;
}
