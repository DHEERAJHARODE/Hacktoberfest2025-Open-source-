#include <bits/stdc++.h>
 
using namespace std;
// Some typedef's
typedef long long ll;
typedef unsigned long long ull;
const int inf = 1e9 + 7;
const double eps = 1e-6;
const double pi = 1.00 * acos(-1.00);
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;
int main(){
   IOS;
   int n;
   cin>>n;
   vector<int>v(n,0);
   for(int i=0;i<n;i++){
    cin>>v[i];
   }
   int max=INT_MIN,min=INT_MAX,l=0,k=0;
   for(int i=0;i<n;i++){
    if(v[i]>=max){
        max=v[i];
        k=i;
    }
   }
   for(int i=0;i<n;i++){
    if(v[i]<=min){
        min=v[i];
        l=i;
    }
   }
   if(v[0]==max && v[n-1]==min){
    cout<<0<<"\n";
   }

else{
   if(l<=(n/2) && k>=(n/2)){
    cout<<k+(n-l-1-1)<<"\n";
   }
   else{
    cout<<k+n-l-1<<"\n";
   }
}

return 0;
}