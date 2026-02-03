class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> answer;
    bool counter =false;
    for(int i=0;i<nums.size()-1;i++){
        for(int j=i+1;j<nums.size();j++){
            if(counter!=true){
                if(nums[j]==target-nums[i]){
                    counter =true;
                     answer.push_back(i);
                     answer.push_back(j);
                     break;
                }    
            }
        }
    }
    if(counter==false){
         answer.push_back(-1);
         answer.push_back(2);
    }
     return answer;    
  }
};