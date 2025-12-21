#include <iostream>
#include <algorithm>

int calcGCD(int n, int m){
    int gcd=1, i;
    for(i=1; i<=std::min(n, m); i++){
        if(n%i==0 && m%i==0){
            gcd = i;
        }
    } 
    return gcd;
}

int main() {
    int n, m;
    std::cout << "Enter two numbers: ";
    std::cin >> n >> m;
    
    int result = calcGCD(n, m);
    std::cout << "GCD of " << n << " and " << m << " is: " << result << std::endl;
    
    return 0;
}
