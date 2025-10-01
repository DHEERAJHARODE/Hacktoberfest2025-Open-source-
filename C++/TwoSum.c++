#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Function to find indices of two numbers that add up to the target
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> numMap; // Stores number and its index

    for (int i = 0; i < nums.size(); ++i) {
        int complement = target - nums[i];

        // Check if complement exists in the map
        if (numMap.find(complement) != numMap.end()) {
            return {numMap[complement], i};
        }

        // Store the current number with its index
        numMap[nums[i]] = i;
    }

    // If no solution found
    return {};
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = twoSum(nums, target);

    if (!result.empty()) {
        cout << "Indices: " << result[0] << " and " << result[1] << endl;
    } else {
        cout << "No two sum solution found." << endl;
    }

    return 0;
}
