# include <iostream>
using namespace std;

int main() {

  char op;
  float n1, n2;

  cout << "Enter operator: +, -, *, /: ";
  cin >> op;

  cout << "Enter two operands: ";
  cin >> n1 >> n2;

  switch(op) {

    case '+':
      cout << n1 << " + " << n2 << " = " << n1 + n2;
      break;

    case '-':
      cout << n1 << " - " << n2 << " = " << n1 - n2;
      break;

    case '*':
      cout << n1 << " * " << n2 << " = " << n1 * n2;
      break;

    case '/':
      cout << n1 << " / " << n2 << " = " << n1 / n2;
      break;

    default:
      cout << "Error! Operator entered is not correct";
      break;
  }

  return 0;
}
