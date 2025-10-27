class Solution {
public:
        bool isPalindrome(int x) {
    if(x<0)
    return false;
    int rem,temp=x;
    long int rev=0;
    while(temp!=0)
    {
        rem=temp%10;
        rev=rev*10+rem;
        temp/=10;
    }
    return (rev==x);
        
    }
};
