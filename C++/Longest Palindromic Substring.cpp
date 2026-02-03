class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        int maxLength=1;
        int start=0;
        int low,high;
        for(int i=0;i<s.length();i++){
             low=i-1;
             high=i+1;
            while(low>=0 && s[i]==s[low]){
                low--;
            }
            while(high<n && s[i]==s[high]){
                high++;
            }
            while(low>=0 && high<n && s[low]==s[high]){
                low--;
                high++;
            }
            int length=high-low-1;
            if(length>maxLength){
                maxLength=length;
                start=low+1;
            }
        }
     
        return s.substr(start,maxLength);
        
    }
};
