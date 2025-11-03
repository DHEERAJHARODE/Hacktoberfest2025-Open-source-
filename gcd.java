class Solution {
    public int gcd(int a,int b)
    {
        while(b!=0)
            {
                int temp=b;
                b=a%b;
                a=temp;
            }
        return a;
    }
    public int gcdOfOddEvenSums(int n) {
        int sumOdd=n*n;
        int sumEven=n*(n+1);
        return gcd(sumOdd,sumEven);
    }
}
