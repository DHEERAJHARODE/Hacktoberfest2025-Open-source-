#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ff              first
#define ss              second
#define int             long long
#define uniq(v)         (v).erase(unique(all(v)),(v).end())
#define pb              push_back
#define pii             pair<int,int>
#define mem1(a)         memset(a,-1,sizeof(a))
#define mem0(a)         memset(a,0,sizeof(a))
#define vi              vector<int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define endl			"\n"
#define ps(x,y)         fixed<<setprecision(y)<<x
#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) 			(x).begin(),(x).end()
#define sz(x) (int)(x).size()
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
 
template<typename T, typename T1>T amax(T &a, T1 b) {if (b > a)a = b; return a;}
template<typename T, typename T1>T amin(T &a, T1 b) {if (b < a)a = b; return a;}
template<typename T>
using pbds = tree<T , null_type , less<T> , rb_tree_tag , tree_order_statistics_node_update>;
const int N = 1e5 + 5;
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i : x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T&& t, V&&... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
 
vector<int> adj[N], rev_adj[N];
vector<int> order;
vector<bool> vis;
 
void dfs1(int u){
	vis[u] = true;
	for(auto v : adj[u])
		if(!vis[v])
			dfs1(v);
	order.pb(u);
}
 
void dfs2(int u){
	vis[u] = true;
	for(auto v : rev_adj[u])
		if(!vis[v])
			dfs2(v);
}
 
void solve(){
    int n, m; cin>>n>>m;
    rep(i,0,m){
    	int u, v; cin>>u>>v;
    	adj[u].pb(v);
    	rev_adj[v].pb(u);
    }
 
    vis.assign(n+1, false);
 
    rep(i,1,n+1)
    	if(!vis[i])
    		dfs1(i);
 
    reverse(all(order));
    vis.assign(n+1, false);
 
    int a = -1;
 
    for(auto u : order)
    	if(!vis[u]){
    		dfs2(u);
    		if(a==-1){
    			a = u;
    		}else{
    			cout<<"NO"<<endl;
    			cout<<u<<" "<<a<<endl;
    			return;
    		}
    	}
    
    cout<<"YES"<<endl;
}
	
int32_t main(){
    IOS;
   	solve();
    return 0;
}
