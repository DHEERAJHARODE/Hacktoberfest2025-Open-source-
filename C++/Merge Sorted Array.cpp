#include <bits/stdc++.h>
using namespace std;
vector<int>  merge(vector<int> &v1,vector<int> &v2)
{
   v1.push_back(INT_MAX);
   v2.push_back(INT_MAX);
   vector<int> v;
   int i=0,j=0;
   while(i<v1.size() && j<v2.size())
   {
    if(v1[i]==INT_MAX && v2[j]==INT_MAX)
    break;

    if(v1[i]<v2[j])
   { v.push_back(v1[i]);
   i++;

   }
   else
   {
    v.push_back(v2[j]);
    j++;

   }


   }
   return v;

}
int main(int argc, char const *argv[])
{
vector<int> v1={1,2,5,9,11};
vector<int> v2={3,4,6,10,12};
vector<int> v=merge(v1,v2);
for(int i=0;i<v.size();i++)
{
    cout<<v[i]<<" ";

}

    return 0;
}
