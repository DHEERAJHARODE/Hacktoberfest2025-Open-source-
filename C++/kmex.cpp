#include <iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
#include<climits>
#define pi 3.1415926536
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;cin>>t;
    while(t--){
        int n,m,k;
        cin>>n>>m>>k;
        int arr[n];
        int mexx;
        set<int> s;
        vector<int> v;
        bool flag=true;
        int maxx=INT_MIN;
        bool flag2=false;
        bool flag3=true;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            maxx=max(maxx,arr[i]);
            if(arr[i]==k){
            continue;
            }
            v.emplace_back(arr[i]);
            s.insert(arr[i]);
        }
        if(k<=maxx+1){
            flag2=true;
        }
        
        for(int i=0;i<=k;i++){
            if(s.find(i)== s.end()){
                mexx=i;
                break;
            }
        }

        if(k>mexx){
            flag3=false;
        }
        bool condition =false;
        set<int>::iterator it;
        int counter=0;
        s.insert(mexx);
        for(it = s.begin();it!=s.find(mexx);it++){
        counter++;
        }

        if(m>=counter){
            condition = true;
        }
        if(m<=v.size() and flag2 and flag3 and condition){
            cout<<"YES"<<"\n";
        }
        else{
            cout<<"NO"<<"\n";
        }
    }
    return 0;
}
