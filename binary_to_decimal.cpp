#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
int main()
{
    int num;
    cout << "enter your binary number " << endl;
    cin >> num;
    int r = 0;
    int i = 0;
    while (num != 0)
    {
        int digit = num % 10;
        num /= 10;
        r = r + digit * pow(2, i);
        ++i;
    }
    cout << r;
    return 0;
}
