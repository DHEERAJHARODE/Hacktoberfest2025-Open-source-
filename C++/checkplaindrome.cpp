// Check Palindrome (recursive)
// Send Feedback
// Check whether a given String S is a palindrome using recursion. Return true or false.
// Input Format :
// String S
// Output Format :
// 'true' or 'false'
// Constraints :
// 0 <= |S| <= 1000
// where |S| represents length of string S.
// Sample Input 1 :
// racecar
// Sample Output 1:
// true
// Sample Input 2 :
// coding
// Sample Output 2:
// false

#include <iostream>
#include<cstring>
using namespace std;
bool check(char input[],int s, int e){
    if(s>=e){
        return true;
    }
    if(input[s]!=input[e]){
        return false;
        check(input,s+1,e-1);
    }

}
bool checkPalindrome(char input[]) {
    int k=strlen(input);
    check(input,0,k-1);
}
int main() {

    char input[50];
    cin >> input;

    if(checkPalindrome(input)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}
