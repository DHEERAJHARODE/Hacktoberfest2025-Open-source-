 /* THE SLAYER */
 
 
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define pb push_back
#define pp pop_back
#define ff first
#define ss second
#define FOR(i,a,b)      for (int i = (a); i < (b); ++i)
#define F0R(i,a)        FOR(i,0,a)
#define ROF(i,a,b)      for (int i = (b) - 1; i >= (a); --i)
#define R0F(i,a)        ROF(i,0,a)
#define rep(a)          F0R(_, a)
#define each(a, x)      for (auto& a : x)
#define vi vector<int>
#define vs vector<string>
#define vll vector<long long>
#define setint set<int>
#define mapint map<int, int>
#define pll pair<long, long>
#define pii pair<int, int>
#define mod 1000000007
#define inf (1LL<<60)
#define all(x) (x).begin(), (x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll,pair<ll,ll>>
#define goog(tno) cout << "Case #" << tno <<": "
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define read(x) int x; cin >> x;
#define yes cout<<"YES"<<"\n"
#define no cout<<"NO"<<"\n"
#define l "\n"
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;


int missing(int arr[],int n){
	int sum=0;
	int sum1=0;
	for (int i = 0; i <n; ++i)
	{
		/* code */
		sum1+=arr[i];
	}
    for(int i=0;i<=n;i++){
        sum+=i;
    }
    int res=sum-sum1;
    return res;
}
int main(){
	int n;
	cin>>n;
	int arr[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}
	cout<<missing(arr,n)<<l;
}


 















