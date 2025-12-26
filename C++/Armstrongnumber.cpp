#include <iostream>
using namespace std;
int main()
{
    int newN;
    cout<<"Enter A number to check : ";
    cin >> newN;
    int n = newN;
    int temp;
    // int sum=0;
    int arm = 0;
    while (n)
    {
        temp = n % 10;
        n /= 10;
        // sum+=temp;
        cout << temp << " ";
        cout << endl;
        arm += temp * temp * temp;
        // cout<<"Sum"<<sum<<endl;
    }
    cout << endl;
    // cout<<arm;
    // cout<<newN;
    if (arm == newN)
    {
        cout << newN << " is a Armstrong number";
    }
    else
    {
        cout << newN << " is not a Armstrong number";
    }

    return 0;
}
