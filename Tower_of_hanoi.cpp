#include <bits/stdc++.h>
#define lli long long
using namespace std;
lli dp[202];
int main()
{
int t,n;
lli x,y;
cin >> t;
assert(t<=10);
while ( t-- ) {
cin >> n;
assert(n<=200);
vector < pair<lli,lli> > v;
for ( int i = 0; i < n; i++ ) {
cin >> x >> y;
assert(x<=1000000000);
assert(y<=1000000000);
v.push_back(make_pair(x,y));
}
sort(v.begin(),v.end());
dp[0] = v[0].second;
lli ans = v[0].second;
for ( int i = 1; i < n; i++ ) {
dp[i] = v[i].second;
for ( int j = 0; j < i; j++ ) {
if ( v[i].second > v[j].second && v[i].first > v[j].first ) dp[i] = max(dp[i], dp[j]+v[i].second);
}
ans = max(ans, dp[i]);
}
cout << ans << endl;
}
return 0;
}
