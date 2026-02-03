// Duplicates in an array
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    cin>>str;
    map<char,int> count;
    for(int i=0;i<str.length();i++)
    {
        count[str[i]]++;
    }
    for(auto it:count)
    {
        if(it.second>1)
        {
            cout<<it.first<<", count= "<<it.second<<"\n";
        }
    }
}
