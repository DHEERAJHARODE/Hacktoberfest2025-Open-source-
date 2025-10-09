#include <bits/stdc++.h>
using namespace std;

int bin_num(string s)
{
     int num = stoi(s);
     int ans = 0;
     int rem = 1;
     while (num != 0)
     {
          int x = num % 10;
          ans = ans + x * rem;
          num = num / 10;
          rem *= 2;
     }
     return ans;
}

string num_bin(int num3)
{
     int num4 = 0;
     while (num3 > 0)
     {
          int x = num3 % 2;
          num4 = num4 * 10 + x;
          num3 = num3 / 2;
     }

          return to_string(num4);
}

string addBinary(string a, string b)
{
     int num1 = bin_num(a);
     int num2 = bin_num(b);

     int num3 = num1 + num2;
     string num4 = num_bin(num3);
     cout << num1 << " " << num2 << " " << num3 << " " << num4;
     return num4;
}

int main()
{
     // string i = addBinary("11", "1");

     // cout << bin_num("1010");
     cout << num_bin(10);
     return 0;
}