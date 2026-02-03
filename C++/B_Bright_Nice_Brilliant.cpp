//                                       ॐ नमः शिवाय
//                                    ------------------

#include <bits/stdc++.h>
using namespace std;

#define himanshud959         \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define INF 1000000000000000003
#define mod 1e9 + 7
#define ll long long
#define V(i) vector<i>
#define P(i, j) pair<i, j>;
#define F first
#define S second
#define pb(x) push_back(x)
#define pf(x) push_front(x)
#define ppf pop_front()
#define ppb pop_back()
#define mp(n, m) make_pair(n, m)
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define rep(_, a, b) for (size_t _ = a; _ < b; _++)
#define repp(_, a, b) for (size_t _ = a; _ <= b; _++)

#define sz(x) (int)x.size()
#define R return
#define str string
#define c(x) cout << (x) << '\n';
#define cyes cout << "YES" << '\n';
#define cno cout << "NO" << '\n';
#define csum cout << sum << '\n';
#define cans cout << ans << '\n';
#define ccnnt cout sum << '\n';
#define cmone cout << '-1' << '\n';
#define cone cout << '1' << '\n';
#define czero cout << '0' << '\n';
#define nl "\n"

#define get(t) \
    int t;     \
    cin >> t;
#define getl(t) \
    ll t;       \
    cin >> t;
#define zero(t) int t = 0;
#define t int t;
//---------Function for taking input in vector----------
#define getv(n)       \
    vector<int> a(n); \
    for (auto &i : a) \
    {                 \
        cin >> i;     \
    }
#define getunique(v)                                  \
    {                                                 \
        sort(v.begin(), v.end());                     \
        v.erase(unique(v.begin(), v.end()), v.end()); \
    }

//---------Function for finding No. of digits---------
int cntDigit(int temmp)
{
    zero(ans) while (temmp)
    {
        ans++;
        temmp /= 10;
    }
    R ans;
}

/*----------Execution of main function i.e 'myTask'----------*/
void myTask()
{
    get(n)
        repp(_, 1, n)
    {
        repp(__, 1, _)
        {
            if (__ == 1 or __ == _)
            {
                cout << 1 << " ";
            }
            else
            {
                cout << 0 << " ";
            }
        }
        cout << nl;
    }
}

int32_t main()
{
    himanshud959 /* FIO */

#ifndef ONLINE_JUDGE
        freopen("inp.txt", "r", stdin);
    freopen("opt.txt", "w", stdout);
#endif

    get(_);
    while (_--)
    {
        /*---------Calling to main function i.e 'myTask'---------*/
        myTask();
    }
    R 0;
}
