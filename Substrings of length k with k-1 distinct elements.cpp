class Solution {
  public:
    int countOfSubstrings(string s, int k) {
       int ans=0;
       unordered_map<char,int>m;
       for(int i=0;i<k;i++)
       m[s[i]]++;
       if(m.size()==k-1)
       ans++;
       for(int i=k;i<s.length();i++)
       {
           if(m[s[i-k]]==1)
            m.erase(s[i-k]);
            else
            m[s[i-k]]--;
            m[s[i]]++;
            if(m.size()==k-1)
            ans++;
       }
       return ans;
    }
};
