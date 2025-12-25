class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int i=0,j=n-1;
        int maxarea=(j-i)*min(height[i],height[j]);
        while(i<j){
            if(height[i]<height[j])i++;
            else
            j--;
            maxarea=max(maxarea,(j-i)*min(height[j],height[i]));
        }
        return maxarea;
    }
};
