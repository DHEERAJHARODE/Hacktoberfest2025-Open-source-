#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
       
       unordered_map<int,int> mp;
       int *ans = new int[2];
       for(int i=0;i<n;i++) {
           mp[arr[i]]++;
       }
       for(int i=1; i<=n; i++) {
          if(mp[i] == 2) ans[0] = i;
          if(mp[i] == 0) ans[1] = i;
       }
       return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends
