#include <bits/stdc++.h>
using namespace std;

#define ll long long
 
void SieveOfEratosthenes(ll n)
{ 
    bool isPrime[n + 1];
    memset(isPrime, true, sizeof(isPrime));
 
    for (ll num = 2; num * num <= n; num++) {       
        if (isPrime[num] == true) {        
            for (ll i = num * num; i <= n; i += num)
                isPrime[i] = false;
        }
    }
 
    // Print all isPrime numbers
    for (ll num = 2; num <= n; num++)
        if (isPrime[num])
            cout << num << " ";
}
  
int main()
{ 
    ll n;
    cout<<"Enter a number upto which you want to find Prime numbers"<<endl;
    cin>>n;
    cout << "Following are the Prime numbers smaller "
         << " than or equal to " << n << endl;
    SieveOfEratosthenes(n);
    return 0;
}