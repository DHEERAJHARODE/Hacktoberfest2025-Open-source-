#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Custom comparator function for sorting.
    // Can be a static function, a lambda, or a struct.
    static bool comp(const pair<int, int>& a, const pair<int, int>& b) {
        // If completion times are the same, sort by the original order number.
        if (a.first == b.first) {
            return a.second < b.second;
        }
        // Otherwise, sort by the completion time.
        return a.first < b.first;
    }

    vector<int> permute(vector<vector<int>>& arr, int n) {
        // A vector to store pairs of {completion_time, original_order_number}.
        vector<pair<int, int>> orders;

        for (int i = 0; i < n; i++) {
            int arrival_time = arr[i][0];
            int prep_time = arr[i][1];
            int completion_time = arrival_time + prep_time;
            
            // Store the completion time and the 1-based order number.
            orders.push_back({completion_time, i + 1});
        }

        // Sort the orders using our custom comparison logic.
        sort(orders.begin(), orders.end(), comp);

        // Create the result vector to store just the sequence of order numbers.
        vector<int> result;
        for (int i = 0; i < n; i++) {
            result.push_back(orders[i].second);
        }

        return result;
    }
};
