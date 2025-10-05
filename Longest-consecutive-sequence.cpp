class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s;
        int n=nums.size();
        if(n==0) return 0;
        for(int i=0;i<n;i++){
            s.insert(nums[i]);
        }
        int longest=1;
        for(auto val:s){
            if(s.find(val-1)==s.end()){
                int count=1;
                int x=val;
                while(s.find(x+1)!=s.end()){
                    x++;
                    count++;
                }
                longest=max(longest,count);
            }
        }
        return longest;
    }
};
