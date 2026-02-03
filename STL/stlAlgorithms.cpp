#include<bits/stdc++.h>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{

    vector<int> v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);


    cout<<"Binary search "<<binary_search(v.begin(),v.end(),5)<<endl;

    string abcd = "abcd";
    reverse(abcd.begin(),abcd.end());
    cout<<abcd<<endl;


}