class Solution {
public:
    void nextPermutation(vector<int>& arr) {
        int n=arr.size(),i,j;
        for(i=n-2;i>=0;i--){
            if(arr[i]<arr[i+1]) break;
        }
        if(i<0) reverse(arr.begin(),arr.end());
        else{
            for(j=n-1; j>=0; j--){
                if(arr[j]>arr[i]) break;
            }
            swap(arr[i],arr[j]);
            reverse(arr.begin()+i+1,arr.end());
        }
    }
};
