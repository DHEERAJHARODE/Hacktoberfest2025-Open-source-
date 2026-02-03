/******************************************************************************

C++ program to check palindrome

*******************************************************************************/
#include <iostream>
using namespace std;

bool isPalindrome (string str)
{
  int j = str.length () - 1;

  for (int i = 0; i < j; i++, j--)
    {
      if (str[i] != str[j])
	{
	  return false;
	}
    }

  return true;
}

int main ()
{
  string word;
  cin>>word;
  if (isPalindrome (word))
	{
	  cout << word << " -> Palindrome" << endl;
	}
  else
	{
	  cout << word << " -> Not a Palindrome" << endl;
	}
cout<<word.length();
  return 0;
}

