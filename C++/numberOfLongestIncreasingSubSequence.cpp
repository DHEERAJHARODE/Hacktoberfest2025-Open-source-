#include<bits/stdc++.h>
using namespace std;



int numberOfLongestIncreasingSubsequence(vector<int>& arr, int n)
{
	// Write your code here.
	vector<int> dp(n,0);
	vector<int> cnt(n,0);
    int maxi =0;
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[j]<arr[i] && dp[i]<dp[j]+1){
                dp[i]=dp[j]+1;
                cnt[i]=cnt[j];
            }
            else if(arr[j]<arr[i] && dp[i]==dp[j]+1){
                // dpf[i]=dpf[j]+1;
                cnt[i]+=cnt[j];
            }   
        }
        maxi= max(dp[i],maxi);
    }

    int num=0;
    for(int i=0;i<n;i++){
        if(dp[i]==maxi)num+=cnt[i];
    }
    return num; 


}





int main(){

}