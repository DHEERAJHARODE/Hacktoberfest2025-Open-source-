// Deliver Boy can able take 
// either 
// 2 weight boxes or 3 weight boxes

// find the minimum number of trips

// Example - [ 1,5,2,1,1,1,1,1,1,1,1,1,1,1,1,5,5,5,5,2,2,2,2,2,2,4,4,4,4,4,4,4,4]

// 1 -> 13 (3*3+2*2) = 3+2 = 5, --> 13%3=1 --> then ((13-1)%3)+1 = 5
// 5 -> 5 (1*3+1*2) = 1+1 = 2, --> 5%3=2 --> then ((5-2)%3)+1 = 2
// 2 -> 7 (1*3+2*2) = 1+2 = 3 , --> 7%3=1 --> then ((7-1)%3)+1 = 3 
// 4 -> 8 (2*3+1*2) = 2+1 = 3 --> 8%2=2 --> then ((8-2)%3)+1= 3

// Ans - 5+2+3+4 = minNumOfTrip = 14

#include <bits/stdc++.h>

using namespace std;


int getMinimumTrips(vector<int> weights) {
   
 
  if(!weights.size()) return 0;
  
  map<int,int> m;
  for(int i=0;i<weights.size();i++) m[weights[i]]++;
   int trip=0;
  for(auto data : m) 
  {
     // cout<<data.first<<" "<<data.second<<endl;
      if(data.second==1) return -1;
      
      else if(data.second%3==0)  trip+=data.second/3; 
      
      else if(data.second%2==2)  trip+=((data.second-2)/3)+1;
      
      // if remainder left one on dividing by 2
      else trip+=(data.second-1)/3+1;
  }
  
  return trip; 
}

int main()
{
     vector<int> weights;
     int n=0;
     cin>>n;
     
     for(int i=0;i<n;i++)
     {
          int data=0;
          cin>>data;
          weights.push_back(data);
     }
     
     cout<<getMinimumTrips(weights);
    return 0;
}
