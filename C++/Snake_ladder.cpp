#include <climits>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std; 

int t[31];
int sol(int i, unordered_map<int, int>& h)
{
    if (i >= 30)
        return 0;
    else if (t[i] != -1)
        return t[i];

    int min_value = INT_MAX;

    for (int j = 1; j <= 6; j++) {
        int k = i + j;

        if (h.count(k) > 0){
            if (h[k] < k);
        }
            k = h[k];
        }
        min_value = min(min_value, sol(k, h) + 1);
    }
    t[i] = min_value;
    return t[i];
}

int min_throw(int n, vector<int> arr)
{
    for (int i = 0; i < 31; i++) {
        t[i] = -1;
    }
    unordered_map<int, int> h;
    for (int i = 0; i < 2 * n; i += 2) {
        h[arr[i]] = arr[i + 1];
    }
    return sol(1, h);
}

int main()
{
    int N = 8;
    vector<int> arr{ 3,  22, 5,  8, 11, 26, 20, 29, 17, 4,  19, 7, 27, 1,  29, 9 };
    cout << "Min Dice throws required is "  << min_throw(N, arr) << endl;
    return 0;
}
