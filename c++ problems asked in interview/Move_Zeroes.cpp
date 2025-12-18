#include<bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int>& nums, int n) {
        int count=0;
        for(int i=0; i<n; i++)
        {
            if(nums[i]!=0)
            {
                nums[count]=nums[i];
                count++;
            }
        } 
        for(int i=count; i<n; i++)
        {
            nums[i]=0;
        }

        return;
    }
    int main()
    {

        int n;
        cin>>n;
        vector<int> nums(n);
        for(int i=0;i<n;i++)
        cin>>nums[i];
        moveZeroes(nums,n);
        for(int i=0;i<n;i++)
        cout<<nums[i]<<" ";
        return 0;
    }
