//Fibonacci Series using Memoization (Dynamic Programming)

#include<iostream>

using namespace std;

int fib(int n, int *fibArray)
{
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;
    if(fibArray[n] != 0)
        return fibArray[n];
    fibArray[n] = fib(n-1, fibArray) + fib(n-2, fibArray);
    return fibArray[n];
}

int main(){
    int n;
    cin >> n;
    int fibArray[n+1];
    for(int i = 0; i <= n; i++)
        fibArray[i] = 0;
    cout << fib(n, fibArray) << endl;
    return 0;
}



//Fibonacci Series using Tabulation (Dynamic Programming)

#include<iostream>

using namespace std;

int fibo(int n){
    int arr[n+1];
    arr[0] = 0;
    arr[1] = 1;
    for(int i = 2; i <= n; i++){
        arr[i] = arr[i-1] + arr[i-2];
    }
    return arr[n];
}

int main(){
    int n;
    cin >> n;
    cout << fibo(n) << endl;
}
