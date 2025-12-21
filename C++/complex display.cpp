#include <iostream>
using namespace std;

class Complex {
    public:
    float real;
    float imag;
    
    void getReal() {
        cin >> real;
    }
    
    void getImag() {
        cin >> imag;
    }
    
    void display() {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {
	
	
	Complex comp[10];
	
	for (int i = 0; i < 10; i++) {
	    cout << "Input Complex # " << i+1 << endl;
	    cout << "Real part : " << endl;
	    comp[i].getReal();
	    cout << "Imaginary part : " << endl;
	    comp[i].getImag();
	}
	
	cout << endl;
	
	for (int i = 0; i < 10; i++) {
	    cout << "Complex # " << i+1 << " : ";
	    comp[i].display();
	}
	
	
	return 0;
}
