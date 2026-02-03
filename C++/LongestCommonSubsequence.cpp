#include <bits/stdc++.h>
using namespace std;
int LCS(string str1, string str2)
{
  int length1 = str1.size();
  int lenght2 = str2.size();
  int dp[length1 + 1][lenght2 + 1];	// Declared the DP 2-D matrix ;
  for (int i = 0; i <= length1; i++)
    {
    for (int j = 0; j <= lenght2; j++)
	{
	    if (i == 0 || j == 0)
	         {
	              dp[i][j] = 0;	//If one of the string length becomes 0 LCS will be 0 ;
		 }
	     else if (str1[length1 - i] == str2[lenght2 - j])
	           {
	                dp[i][j] = 1 + dp[i - 1][j - 1];	// when the first Character Matches 
	               }
	      else
		 {
	      int a = dp[i - 1][j];	// when first Character of first string is considered in the LCS solution .
               int b = dp[i][j - 1];	// when first Character of second string is considered in the LCS solution .
               int c = dp[i - 1][j - 1];	// when none of the first character is considered in the solution .
              dp[i][j] = max(a, max(b, c));
			}
		}
	}
   return dp[length1][lenght2];
}
int main()    
{
	string str1, str2;
	cin >> str1;
	cin >> str2;
	cout << "LCS of " << str1 << " and " << str2 << " is " << LCS(str1, str2) << endl;
	return 0;
}
