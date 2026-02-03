// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    struct tuple
    {

        int start, end, id;
    };

    static bool cmp(tuple a, tuple b)
    {
        if (a.end != b.end)
            return a.end < b.end;

        return a.id < b.id; //DONT COMPARE START TIME
    }
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here

        vector<tuple> v(n);

        for (int i = 0; i < n; i++)
        {
            v[i].start = start[i];
            v[i].end = end[i];
            v[i].id = i + 1;
        }

        sort(v.begin(), v.end(), cmp);

        int prevEnd = v[0].end; //first meeting will always occur
        int count = 1;

        for (int i = 1; i < n; i++)
        {
            if (v[i].start > prevEnd)
            {
                count++;
                prevEnd = v[i].end;
            }
        }
        return count;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++)
            cin >> start[i];

        for (int i = 0; i < n; i++)
            cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
} // } Driver Code Ends