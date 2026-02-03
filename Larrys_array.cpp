// git-book link : https://jordy-bro.gitbook.io/golok/
// problem statement : Larry's Array
// author : James Marcus Peter
// Date: 09.10.2022


#include <bits/stdc++.h>
#define ull unsigned long long

using namespace std;

int main() 
{
    ull t;
    cin >> t;
    
    while(t--)
    {
        ull n;
        cin >> n;
        
        map<int,int> mp;
        ull count = 0;
        for(int i = 0 ; i < n ; i++)
        {
            ull tmp;
            cin >> tmp;
            if(i != 0)
            {
                for(auto it = mp.begin() ; it != mp.end() ; it++)
                {
                    if(it->first <= tmp)
                    {
                        count += it->second;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            mp[tmp]++;
        }
        cout << count << '\n';
    }
    
	return 0;
}
