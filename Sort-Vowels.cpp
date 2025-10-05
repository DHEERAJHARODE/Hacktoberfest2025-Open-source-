class Solution {
private:
    bool isVowel(char ch){
        string vowels = "aeiouAEIOU";
        return vowels.find(ch) != string :: npos;
    }
public:
    string sortVowels(string s) {
        vector<char>arr;
        for(int i= 0;i<s.length();i++){
            if(isVowel(s[i]))
            {
                arr.push_back(s[i]);
                
            }
        }
        sort(arr.begin(),arr.end());
        int j = 0;
        for(int i= 0;i<s.length();i++){
            if(isVowel(s[i])){
                s[i] = arr[j];
                j++;
            }
        }
        return s;
    }
};
