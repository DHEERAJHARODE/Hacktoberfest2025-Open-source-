#include<bits/stdc++.h>
using namespace std;

void get_inputs(int &n1,int &n2){
//objective: to get he user input for the two numbers
//Input parameters: the value of the referenced variables
//Output parameters: None
    cout<<endl<<"Enter the First Number:";
    cin>>n1;
    cout<<endl<<"Enter the Second Number:";
    cin>>n2;
}


void display_output(int result, int num1,int num2){
//objective: to show the Greatest common divisor of the numbers
//Input parameters: the value of GCD and the numbers
//Output parameters: None
    cout<<endl<<"The Greatest Common Divisor of "<<num1<<" and "<<num2<<" is:"<<result;
}

int GCD(int dividend,int divisor){
//objective: to find the greatest common divisor of two numbers
//Input parameters: Numbers as divisor and dividend
//Output parameters: the GCD of the numbers
//Approach: We will use modulo operator to find remainder and make
//it as divisor and the number divisor before will become dividend
//till divisor becomes zero
    if(divisor==0){
        return dividend;
    }
    int digit = dividend%divisor;
    dividend = divisor;
    divisor = digit;
    return GCD(dividend,divisor);
}

int LCM(int n1,int n2){
//objective: to find the Least Common Multiple of the two numbers
//Input parameters: the value of the numbers
//Output parameters: the value of the LCM of two numbers
    return (n1*n2)/GCD(n1,n2);
}

void display_lcm(int res, int a, int b){
//objective: to show the LCM of two numbers
//Input parameters: the value of LCM of the numbers and the value of numbers
//Output parameters: None
    cout<<"The Least Common Multiple of "<<a<<" and "<<b<<" is:"<<res;
}

int main(){
//objective: to find the Greatest Common divisor of two numbers
//Input parameters: None
//Output parameters: None
    int m,n;
    get_inputs(m,n);
    int res = GCD(max(m,n),min(m,n));
    display_output(res,m,n);
    int res1 = LCM(m,n);
    cout<<endl;
    display_lcm(res1,m,n);
    return 0;
}

//Time Complexity: O(n) -> Recursion for GCD
//Space Complexity: O(1)
