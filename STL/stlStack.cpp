#include<bits/stdc++.h>
#include<stack>
using namespace std;

int main()
{

    stack<string> s;

    s.push("One");
    s.push("Two");
    s.push("Three");

    cout<<"The top of the stack is "<<s.top()<<endl;


    s.pop();

    cout<<"The top of the stack after poping is "<<s.top()<<endl;

    return 0;


}