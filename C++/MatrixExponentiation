#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <memory>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

#define FOR(i,a,b) for(int (i) = (a); (i) < (b); ++(i))
#define RFOR(i,a,b) for(int (i) = (a)-1; (i) >= (b); --(i))
#define CLEAR(a) memset((a),0,sizeof(a))
#define INF 1000000000
#define PB push_back
#define ALL(c) (c).begin(), (c).end()
#define pi 2*acos(0.0)
#define SQR(a) (a)*(a)
#define MP make_pair
#define MAX 110
#define si(n) scanf("%d",&n);
#define sl(n) scanf("%lld",&n);
#define MOD 1000000007
#define printl(n) ("%lld\n",n);
#define ll long long
using namespace std;
#define int long long
int f[2][2] ;


void multiply(int F[2][2],int M[2][2])
{
   ll x =  F[0][0]*M[0][0] + F[0][1]*M[1][0];
  ll y =  F[0][0]*M[0][1] + F[0][1]*M[1][1];
  ll z =  F[1][0]*M[0][0] + F[1][1]*M[1][0];
  ll w =  F[1][0]*M[0][1] + F[1][1]*M[1][1];

  F[0][0] = x%MOD;
  F[0][1] = y%MOD;
  F[1][0] = z%MOD;
  F[1][1] = w%MOD;

}

void fastPower(int m[2][2],int n){
if(n==0||n==1)
    return ;

fastPower(m,n/2);
multiply(m,m);

if(n%2!=0)
    multiply(m,f);
}

int solveLinearRec(int m[2][2],int colVec[2][1],int n){
int i,j;
for(i=0;i<2;i++){
    for(j=0;j<2;j++){
        f[i][j] = m[i][j];
    }
}
fastPower(m,n-1);
// Multiply a with ColVector 1 , 3 //
return (m[0][0] + 3*m[0][1]%MOD)%MOD;

}




main(){
int t;
int n;
cin>>t;
while(t--){
    int n;
    cin>>n;

    int m[2][2] = {{0,1},{2,2}};
    int colVector[2][1] = {1,3};

    if(n==1)
        cout<<"1"<<endl;
    else if(n==2)
        cout<<"3"<<endl;
    else
   printf("%lld\n",solveLinearRec(m,colVector,n));
}
return 0;
}
