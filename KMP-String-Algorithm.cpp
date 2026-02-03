#include <bits/stdc++.h>
using namespace std;
#define ll long long int 
#define MAX_N 100005
int reset[MAX_N];

void kmp_pre(string pat){
    int i=0,j=1;
    reset[0]=-1;
    while(j>=0 && pat[i]!=pat[j]){
        j=reset[j];
    }
    i++,j++;
    reset[i]=j;
}

void kmp_search(string str,string pat){
    kmp_pre(pat);
    int i=0,j=0;
    while(i<str.size()){
        while(j>=0 && str[i]!=pat[j]){
            j=reset[j];
        }
        i++,j++;
        if(j==pat.size()){
            cout<<"pattern is found at"<<i-j<<endl;
            j=reset[j];//for next occurence
        }
    }
}

int main() {
    for(int i=0;i<MAX_N;i++){
        reset[i]=-1;
    }
    string str,pat;
    cin>>str>>pat;
    kmp_search(str,pat);
    return 0;
}
