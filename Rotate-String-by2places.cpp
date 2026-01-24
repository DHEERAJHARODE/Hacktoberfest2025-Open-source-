#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    bool isRotated(string str1, string str2)
        {
            if(str1.size()!=str2.size() || str1.size() == 1) return 0;
            string concat = str1 + str1;
            if(concat.find(str2) == 2 || concat.find(str2) == str1.size()-2) return 1;
            else return 0;
        }
};
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        string b;
        cin>>s>>b;
        Solution obj;
        cout<< obj.isRotated(s, b)<<endl;
    }
    return 0;
}
