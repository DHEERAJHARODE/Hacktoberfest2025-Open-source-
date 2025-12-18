#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int call_by_value(int n){
	cout << "address of n in call_by_value function : " << &n<<endl;
	n *=n;
	return n;
}

int main() {
    int n = 8;
    cout << "address of n in main() : " << &n << endl;
    cout << "ans : " << call_by_value(n) << endl;
    cout << "value of n : " << n << endl;

    return 0;
}
