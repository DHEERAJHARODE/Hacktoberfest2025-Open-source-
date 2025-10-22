class Solution {
public:
    string intToRoman(int num) {
         int normal[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string roman[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        string ans;
        
        //e.g--> 3792
        
        for(int i=0; i<13; i++)
        {
            if(num>=normal[i])
            {
                int times=num/normal[i];
                num-=times*(normal[i]);
                while(times--) ans+=roman[i];
            }
        }
        
        return ans;
    }
};
