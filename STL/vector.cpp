#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin>>n;
    vector<int> v1;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        v1.push_back(a);
    }
    sort(v1.begin(), v1.end());
    for(int i=0;i<n;i++)
    {
       cout<<v1[i]<<" ";
    }
    return 0;
}
