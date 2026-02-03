// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main() {
    int x = 1000;
    int *p;
    p = &x; 
    cout << x << endl; // value of a variable 
	cout << p << endl; // address of a variable 
    cout << *p; //value of pointer 

    return 0;
}
