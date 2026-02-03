#include <iostream>
#include<bits/stdc++.h>
using namespace std;

// Greedy Approach
void Survival(int S, int N, int M){
    // If we can not buy weekly food in 6 days(Mon to Sat) and Surviving days is more than 6 then return "No"
    // Also if M > N return "NO"
    if(((6*N) < (7*M) && S > 6) || (M > N)){
        cout<<"No"<<endl;
    }
    else{
        int days = (M*S)/N; // Formula to get number of buys and if this formula has remainder do day = day + 1;
        if(((M*S)/N) != 0){
            days++;
        }
        cout<<"Yes "<<endl;
        cout<<"Minimum number of days on which you need to buy food from the shop: "<<days<<endl;
    }
}

int main() {
    int S, M, N;

    cout<<"Enter number of days you are required to survive.: ";
    cin>>S;
    cout<<endl;
    cout<<"Enter Maximum unit of food you can buy each day.: ";
    cin>>N;
    cout<<endl;
    cout<<"Enter Unit of food required each day to survive.: ";
    cin>>M;
    cout<<endl;

    int buy = 1;

    Survival(S, N, M);

    return 0;
}
