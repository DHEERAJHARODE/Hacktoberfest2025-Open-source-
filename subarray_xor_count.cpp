#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int countSubarraysWithXOR(vector<int>& A, int B) {
    int count = 0;
    int xorSum = 0;
    unordered_map<int, int> xorCount; // To store the count of XOR values encountered

    for (int i = 0; i < A.size(); i++) {
        xorSum ^= A[i];

        if (xorSum == B) {
            count++;
        }

        // If (xorSum ^ B) is present in the map, it means there are subarrays that can be removed to get XOR equal to B.
        if (xorCount.find(xorSum ^ B) != xorCount.end()) {
            count += xorCount[xorSum ^ B];
        }

        xorCount[xorSum]++;
    }

    return count;
}

int main() {
    vector<int> A = {4, 2, 2, 6, 4};
    int B = 6;

    int result = countSubarraysWithXOR(A, B);
    cout << "Number of subarrays with XOR equal to " << B << ": " << result << endl;

    return 0;
}
