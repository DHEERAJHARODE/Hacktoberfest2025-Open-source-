// we have two arrays in this question nums and cost array so in nums arry
// we have to make all the elemnts eual to  any one of the elemnts in nums array
// we should choose such a number jiska cost minimum ho 
// brut force approch is har elemt ko ek baar choose karo nums array se and cost 
// calculate karo and minimum cost wala return kardo

// optimal approach binary search  se kar sakte hai 
// extreme elemnts nahi lene hai kyuki vo cost zyada lagega
// so we should choose such a number which is in between the array 

typedef long long ll;
  ll findCost(vector<int>& nums, vector<int>& cost, int target) {
    ll result = 0;
    for (int i = 0; i < nums.size(); i++) {
        result += (ll)abs(nums[i] - target) * cost[i];
    }
    return result;
}
    
    

    long long minCost(vector<int>& nums, vector<int>& cost) {
        
        ll ans =INT_MAX;
        int left=*min_element(nums.begin(),nums.end());
        int right=*max_element(nums.begin(),nums.end());

        while(left<=right)
        {
            int mid=left+(right-left)/2;

            ll cost1=findCost(nums,cost,mid);
            ll cost2=findCost(nums,cost,mid+1);

            ans=min(cost1,cost2);

            if(cost2>cost1)
            {
                right=mid-1;
            }
            else
            {
                left=mid+1;
            }
        }
        return ans==INT_MAX ? 0:ans;
    }

    
