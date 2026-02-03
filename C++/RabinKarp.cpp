// Q97 https://leetcode.com/problems/repeated-string-match/submissions/

// Time:O(n)
// Space:O(1)

class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string s="";
        int c=0;
        while(s.size()<b.size()){
            s+=a;
            c++;
        }
        if(s.find(b)<s.size())  //if(s.find(b)!= string::npos)
            return c;
        s+=a;
        c++;
        if(s.find(b)<s.size())
            return c;
        else 
            return -1;
    }
};


//Using Rabin Karp 
class Solution {
private:
    int BASE = 1000000;
public:
    int repeatedStringMatch(string A, string B) {
        if(A == B) return 1;
        int count = 1;
        string source = A;
        while(source.size() < B.size()){
            count++;
            source+=A;
        }
        if(source == B) return count;
        if(Rabin_Karp(source,B) != -1) return count;
        if(Rabin_Karp(source+A,B) != -1) return count+1;
        return -1;
    }
    int Rabin_Karp(string source, string target){
        if(source == "" or target == "") return -1;
        int m = target.size();
        int power = 1;
        for(int i = 0;i<m;i++){
            power = (power*31)%BASE;
        }
        int targetCode = 0;
        for(int i = 0;i<m;i++){
            targetCode = (targetCode*31+target[i])%BASE;
        }
        int hashCode = 0;
        for(int i = 0;i<source.size();i++){
            hashCode = (hashCode*31 + source[i])%BASE;
            if(i<m-1) continue;
            if(i>=m){
                hashCode = (hashCode-source[i-m]*power)%BASE;
            }
            if(hashCode<0)
                hashCode+=BASE;
            if(hashCode == targetCode){
                if(source.substr(i-m+1,m) == target)
                    return i-m+1;
            }
        }
        return -1;
    }
};
