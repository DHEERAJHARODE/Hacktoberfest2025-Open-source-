class Solution {
public:
    int pow10[9] = {1,      10,      100,      1000,     10000,
                    100000, 1000000, 10000000, 100000000};
    inline int swapInc(int x, int i, int y, int j){//i<j
        if(x<=y) return 0;
        return (x-y)*(pow10[j]-pow10[i]);
    }
    int maximumSwap(int num) {
        if (num == pow10[8]) return num;
        vector<char> digit;
        digit.reserve(8);
        int x, d;
        for(x=num, d=0; x>0; x/=10, d++)
            digit.push_back(x%10);
        // brute force at most d*(d-1)/2<= 28 tries
        int maxInc=0;
        for(int i=0; i<d-1; i++)
            for(int j=i+1; j<d; j++)
                maxInc=max(maxInc, swapInc(digit[i], i, digit[j], j));
        return num+maxInc;
    }
};
