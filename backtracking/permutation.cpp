#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void permutation(string &str, int i)
{
    if (i == str.size())
    {
        cout << str << "  ";
        return;
    }
    for (int j = i; j < str.size(); j++)
    {
        swap(str[i], str[j]);
        permutation(str, i + 1);
        swap(str[i], str[j]);
    }
}

int main()
{
    string str = "abc";
    cout << "\n\n";
    permutation(str, 0);
    cout << "\n\n";
    return 0;
}