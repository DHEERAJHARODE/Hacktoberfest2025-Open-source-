#include <iostream>
using namespace std;
 
class ComplexNumber{
  private:
  int real;
  int imaginary;
  public:
  ComplexNumber(int real, int imaginary){
    this->real = real;
    this->imaginary = imaginary;
  }
  void print(){
    cout<<real<<" + i"<<imaginary;
  }
  ComplexNumber operator+ (ComplexNumber c2){
    ComplexNumber c3(0,0);
    c3.real = this->real+c2.real;
    c3.imaginary = this->imaginary + c2.imaginary;
    return c3;
  }
};
int main() {
    ComplexNumber c1(3,5);
    ComplexNumber c2(2,4);
    ComplexNumber c3 = c1 + c2;
    c3.print();
    return 0;
}
