*
  Author Lakshay Goel
  Github profile: https://github.com/mrlakshaygoel
  Problem link: https://www.geeksforgeeks.org/program-to-find-lcm-of-two-numbers/
  Given are two numbers we need to find their LCM
*/
#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long 
ull lcm(ull, ull);
int main()
{
	ull int a, b;
	cin >> a >> b;
	cout << "LCM of " << a << ", " << b << " is: " << lcm(a, b) << endl;
	return 0;
}

ull lcm(ull a, ull b)
{
	ull lcm = 1;
	for(int i = 1;i <= a * b; i++)
	{
		if(i % a == 0 && i % b == 0)
		{
			lcm = i;
			break;
		}
	}
	return lcm;
}
