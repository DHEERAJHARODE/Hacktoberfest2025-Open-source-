#include <bits/stdc++.h>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        map<int,int> m;
        int val;
        for(int i=0;i<nums.size();i++)
        {
            val = target - nums[i];
            if(m.count(val))
            {
                ans.push_back(i);
                ans.push_back(m[val]);
            }
            else
                m[nums[i]]=i;
                
        }
        return ans;
    }

int main()
{
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
    cin>>nums[i];
    int target;
    cin>>target;
    vector<int> answer;
    answer = twoSum(nums, target);
    int m=answer.size();
    for(int i=0;i<m;i++)
    cout<<answer[i]<<" ";

    return 0;
}
