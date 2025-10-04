#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;
        for (int a : asteroids) {
            bool destroyed = false;
            while (!st.empty() && a < 0 && st.back() > 0) {
                if (st.back() < -a) {
                    st.pop_back();
                    continue;
                } else if (st.back() == -a) {
                    st.pop_back();
                }
                destroyed = true;
                break;
            }
            if (!destroyed) st.push_back(a);
        }
        return st;
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter number of asteroids: ";
    cin >> n;

    vector<int> asteroids(n);
    cout << "Enter asteroid values: ";
    for (int i = 0; i < n; i++) {
        cin >> asteroids[i];
    }

    vector<int> result = sol.asteroidCollision(asteroids);

    cout << "Result after collision: ";
    for (int x : result) cout << x << " ";
    cout << endl;

    return 0;
}
