/*
TOPIC : MULTI LEVEL INHERITANCE
EXPLAIN : 
* Derivation of a class from another derived class is called Multilevel Inheritance. 
* Class A is the base class for the derived class B, which in turn serves as a base class for the derived class C. 
* Class B provides a link for the inheritance between A and C and is known as an intermediate base class. 
* The chain A, B, C is known as the inheritance path.

For example in our case base class is TRIANGLE and inherited classes are Equliateral trinagle , Isosceles triangle , Triangle 
*/


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

//this is the base class 
class Triangle{
	public:
		void triangle(){
			cout<<"I am a triangle\n"; 
		}
};

/* 
This is derived class from the base class Triangle
Using public mode means public function's of base class is also the public funtion of inherited class
*/

class Isosceles : public Triangle{
  	public:
  		void isosceles(){
    		cout<<"I am an isosceles triangle\n";
  		}
};


class Equilateral : public Isosceles
{
    public: 
    void equilateral()
    {
        cout<<"I am an equilateral triangle"<<endl;
    }
};

int main(){
  
    Equilateral eqr;
    /*
    calling of different class functions using variable of Equilateral class
     */
    eqr.equilateral(); 
    eqr.isosceles();
    eqr.triangle();
    return 0;
}


/*
Output

I am an equilateral triangle
I am an isosceles triangle
I am a triangle

*/