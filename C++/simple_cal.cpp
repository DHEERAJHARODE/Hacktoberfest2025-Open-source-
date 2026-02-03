#include <iostream>
using namespace std;

int main()
{
    int a, b;
    char op;

    cout << "Enter two numbers: " << endl;
    cin >> a >> b;
    cout << "Enter an operation: " << endl;
    cin >> op;
    cout << "Answer is: " << endl;

    switch (op)
    {
    case '+':
        cout << a + b << endl;
        break;

    case '-':
        cout << a - b << endl;
        break;

    case '*':
        cout << a * b << endl;
        break;

    case '/':
        cout << a / b << endl;
        break;
    }

    return 0;
}
