class Solution {
public:
    string reverseWords(string s) {
        int i=0;
        for(int i=0; i<s.length(); i++) {
            int j=i;
            while(j<s.length() && s[j] != ' ')
                ++j;
            
            int k=j;
            --j;
            while(i<j) {
                swap(s[i], s[j]);
                ++i;
                --j;
            }
            i = k;
        }
        return s;
        
    }
};