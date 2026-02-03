#include <iostream>
#include <string>
using namespace std;

int main() {
string s,t;
    char c;
    getline(cin>>ws,s);
    getline(cin>>ws,t);
    cout<<s.length()<<" "<<t.length()<<endl;
    cout<<s+t<<endl;
    c=s[0];
    s[0]=t[0];
    t[0]=c;
    cout<<s<<" "<<t<<endl;
    return 0;
}