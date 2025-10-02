class Solution {
public:
    string predictPartyVictory(string senate) {
        int cnt=0;
        for(int i=0;i<senate.size();i++)
        {
            if(senate[i]=='R')
            {
                if(cnt<0)
                {
                    senate.push_back('D');
                }
                cnt++;
            }
            else{
                if(cnt>0)
                {
                    senate.push_back('R');
                }
                cnt--;
            }
        }
        return cnt>0?"Radiant":"Dire";
    }
};
