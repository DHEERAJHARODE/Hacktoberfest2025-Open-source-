#include <iostream>
using namespace std;

/*
  Diamond Star Pattern
  Time Complexity: O(n²)
  Space Complexity: O(1)
*/

int main() {
    int n;
    cout << "Enter number of rows: ";
    cin >> n;

    // Upper half
    for (int i = 1; i <= n; i++) {
        // Print spaces
        for (int j = i; j < n; j++)
            cout << " ";
        // Print stars
        for (int j = 1; j <= (2 * i - 1); j++)
            cout << "*";
        cout << endl;
    }

    // Lower half
    for (int i = n - 1; i >= 1; i--) {
        // Print spaces
        for (int j = n; j > i; j--)
            cout << " ";
        // Print stars
        for (int j = 1; j <= (2 * i - 1); j++)
            cout << "*";
        cout << endl;
    }

    return 0;
}
