#include <bits/stdc++.h>
using namespace std;
  
bool isPrime(int n)
{
    // Corner case
    if (n <= 1)
        return false;
  
 
    for (int i = 2; i < n; i++)
        if (n % i == 0)
            return false;
  
    return true;
}


bool isprimeMethod2(int n){
 if (n <= 1) return false; // 0 and 1 are not prime numbers
    if (n <= 3) return true;  // 2 and 3 are prime numbers

    // Check for even numbers and multiples of 3
    if (n % 2 == 0 || n % 3 == 0) return false;

    // Check from 5 to sqrt(n) for any factors
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }

    return true;
}

int main()
{
    isPrime(11) ? cout << " true\n" : cout << " false\n";
    isPrime(15) ? cout << " true\n" : cout << " false\n";
    isprimeMethod2(15) ? cout << " true\n" : cout << " false\n";
    return 0;
}
