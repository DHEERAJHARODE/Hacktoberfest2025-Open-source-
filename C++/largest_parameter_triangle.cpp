

 #include <bits/stdc++.h>

#include <iostream>
using namespace std;
# define test int t; cin>>t; while(t--)
# define ll long long int

    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end()); //we sort the array first 
      int n=nums.size(); 
      for(int i= n-1;i>=2;i--){  //we start from the end of the array 
        //as we have to return the largest parameter and the array is sort

          if(nums[i-2]+nums[i-1]>nums[i]){ //to make a triangle we need to satisfy the a+b>c ///condition
          
              return nums[i]+nums[i-1]+nums[i-2];
          }
      }
      return 0;
    }

    int main(){
        int n;
        cin>>n;
        vector<int> arr;
        for(int j=0;j<n;j++){
            int i;
            cin>>i;
            arr.push_back(i);
        }
      largestPerimeter(arr);
    }
