//                     OBJECT ORIENTED PROGRAMMING 




//CLASS - > class is a description of an Object.

// The building block of C++ that leads to Object-Oriented programming is a Class. It is a user-defined data type, which holds its own data members and member functions,
//  which can be accessed and used by creating an instance of that class. A class is like a blueprint for an object.

// For Example: Consider the Class of Cars. There may be many cars with different names and brand but all of them will share some common properties like all of them will have 
// 4 wheels, Speed Limit, Mileage range etc. So here, Car is the class and wheels, speed limits, mileage are their properties.

// A Class is a user-defined data-type which has data members and member functions.
// Data members are the data variables and member functions are the functions used to manipulate these variables and together these data members and member functions 
// define the properties and behaviour of the objects in a Class.
// In the above example of class Car, the data member will be speed limit, mileage etc and member functions can apply brakes, increase speed etc.
// We can say that a Class in C++ is a blue-print representing a group of objects which shares some common properties and behaviours.


//OBJECT - > object is an instance of a class.
// An Object is an identifiable entity with some characteristics and behaviour. An Object is an instance of a Class. When a class is defined, no memory is allocated
// but when it is instantiated (i.e. an object is created) memory is allocated.

class complex{
    private:
        int a,b;
    public:
        void set_data(int x,int y){
            a = x;             // set_data is a member function 
            b = y;             // here a and b are the atrributes of the object that calls set_data function
        }
        void get_data();  // declaration inside the class
};

// we can define a member function outside the class also 
void complex:: get_data(){  // defination outside the class
    cout<<a<<" "<<b<<endl;
}

// If a function is defined inside a class it is by default a INLINE function.
//To make a function inline which is deeclared outside the class we need to use KEYWORD INLINE

//INSTANCE MEMBER VARIABLES -> ATTRIBUTES/DATA MEMBERS
//INSTANCE MEMBER FUNCTIONS -> METHODS/BEHAVIOURS
//(We call instance member function and variables because they belong to object class member functions and variables are different)


// ----> A state of a object means colllection of values of its attributes , if any value changes state of oobject is changes.
//       OOP says state of an object should not change until a member function is called.
//       Therefore  we generally declare instance member variable as private.











//                           ENCAPSULATION   AND DATA ABSTRACTION 

// Encapsulation: In normal terms, Encapsulation is defined as wrapping up of data and information under a single unit. 
// In Object-Oriented Programming, Encapsulation is defined as binding together the data and the functions that manipulate them.
// Consider a real-life example of encapsulation, in a company, there are different sections like the accounts section, finance section, sales section etc.
// The finance section handles all the financial transactions and keeps records of all the data related to finance.
// Similarly, the sales section handles all the sales-related activities and keeps records of all the sales.
//  Now there may arise a situation when for some reason an official from the finance section needs all the data about sales in a particular month. 
//  In this case, he is not allowed to directly access the data of the sales section. He will first have to contact some other officer in the sales section and 
//  then request him to give the particular data. This is what encapsulation is. Here the data of the sales section and the employees that can manipulate them are 
//  wrapped under a single name “sales section”.


// Encapsulation also leads to data abstraction or hiding. As using encapsulation also hides the data. In the above example, the data of any of the 
// section like sales, 
// finance or accounts are hidden from any other section.


// Abstraction: Data abstraction is one of the most essential and important features of object-oriented programming in C++. 
// Abstraction means displaying only essential information and hiding the details. Data abstraction refers to providing only essential information about the data
// to the outside world, hiding the background details or implementation.
// Consider a real-life example of a man driving a car. The man only knows that pressing the accelerators will increase the speed of the car or 
// applying brakes will stop the car but he does not know about how on pressing accelerator the speed is actually increasing, he does not know about 
// the inner mechanism of the car or the implementation of accelerator, brakes etc in the car. This is what abstraction is.

// Abstraction using Classes: We can implement Abstraction in C++ using classes.
// The class helps us to group data members and member functions using available access specifiers.
// A Class can decide which data member will be visible to the outside world and which is not.

// Abstraction in Header files: One more type of abstraction in C++ can be header files. For example, consider the pow() method present in math.h header file. 
// Whenever we need to calculate the power of a number, we simply call the function pow() present in the math.h header file and pass 
// the numbers as arguments without knowing the underlying algorithm according to which the function is actually calculating the power of numbers.










//                                         Constructors   And Destructor in c++
//Constructor:
//It is a member function of class.
//The name is same as that of a class.
//There is No return type.
//It can Never be static
//constructor is implicitaly invoked when an object is created
//It is used to solve the problem of initialization
//we can overload constructor and parameterized constructor can be made.
//Constructors are instance member functions they can never be static

//compiler internaly invokes default constructer if there is not define one
// if u define any constructor with parameters then compiler will not create any constructor internally 
//compiler also invokes copy constructor internally if user do not define one(shallow)

// copy constructor
complex (complex &c){   //we use '&' or pass by reference because ohterwise iinfinite recusrsion will be there because c is a fromal parameter of type complex and when
    a = c.a;            // in call c1 is passes to it again copy constructor is called for c and this goes on...........
    b = c.b;
}
//in main  complex c2 = c1; or complex c2(c1);

//Desctructor :
//Name is sam as that of class with ~ symbol
//can never be statiic
//no return type
//cannot be overloaded and takes no arguement
// --- > Basically it is the last method which is internally invoked before the object is going to be destroyed
//      its advantage is that let say if there is a pointer in the object which will be destroyed when object is destroyed but the memory that it was pointing to now 
//      cannot be accesd for freed , so in destructor we can free that memory before the pointer is destroyed along with object












//                                             STATIC MEMBERS IN C++ 
//There are basically 3 types
// 1> static local variable   (Also present in c language)
// 2> static member variable  (c++)
// 3> static member fucntion  (c++)

// (1) static local varibale
//      -->Mrmory assigned at start of program
//      --> They are by default initialized to zero;
//      --> There  lifetime is throughtout the program.
void func(){
    static int x  ;  // static local variable  --> by deafualt 0 value ,   it gets memory at the startingof the program and is destroyed only when program is finished
    int y;        // local varibale        -->  by default garbage value ,  it is created and destroyed every time function is called
}

// (2) Static member variable
//      --> Declared inside the class body.
//      --> Must be defined outside the class body
//      -->also known as  ** CLASS MEMBER VARIABLE **
//      -->They do not belong to any particular object but to the whole class
//      -->static member will be there wheter we create a object or not for class ans same copy is used by all objects
//      -->we can use it as  =>  class_name :: variable_name = value; 
//      --> can also be used using object  obj.variable_name = value;
class Account{
    class Account{
    private:
        int balance; // instance member variable
    public:
    static float roi;   //declaration   ,  class member variable
    static void setroi(float r){
        roi = r;                       // class member function  , static member function
    }
};
float Account::roi = 3.5f; //defination : *** IF WE DO NOT WRITE THIS LINE ROI WILL NOT EXIST  ,, IF WE DO NOT GIVE VALUE BY DEAFAULT VALUE IS  0

//(3) static member function
//      -->We use static keyword to delace static member function
//      -->it is called without object              for e.g = Account::setroi(4.5f);
//      -->it can access only static member variable
// We can create a instance member function without using static keyword and use tha to set value of roi but for that we will need a object to call that method and because 
// static member variable exists whether object is created or not so it is better to create and use a static member function as they can be called without obeject














//                              FRIEND FUCNTION  IN C++

//Friend function is not a member function of the class to which it is friend
//Friend function is declared in class with friend keyword
//It must be defined outside the class to which it is friend
//It can access any member of the class to which it is friend (private also)
// it cannt access directly it does through objects of that class
//it has no caller object
//it should not be defined with membership label
class complex{
    private:
        int a,b;
    public:
        void set_data(int x,int y){
            a = x;             
            b = y;            
        }
        friend void func(complex );   // USE friend keyword  , can be declared anywhere public or private does not matter
};
void func(complex c1){   // object of complex clas is passed
    cout<<c1.a<<" "<<c1.b<<endl;   // accessing members using object and dot operator and not like member  functions wich can directly acess
}
main(){
    complex c1(2,3);
    func(c1);           // called directly without any object
}
//we can also do operator overloading using friend function

// cout<<c1 ;  means operator<<(cout,c1);
//inside class declare as =  friend ostream& operator<<(ostream&,complex);
//example code

#include <iostream>
using namespace std;

class complex{
    int a; int b;
public:
    friend ostream& operator<<(ostream&,complex&);
    friend istream& operator>>(istream&,complex&);
};

istream& operator>>(istream & din,complex &c){
    din>>c.a>>c.b;
    return  din;
}

ostream& operator<<(ostream& dout,complex &c){
    dout<<c.a<<" "<<c.b<<endl;
    return  dout;
}

int main() {
     #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 

    complex c;
    cin>>c;
    cout<<c;
    return 0;
}


//ADVANTAGES 
//      ---- >friend function can be friend to more than 1 class and hence we can use objects of different class in a same function if we want some functionality together
//      ---- >MEMBER FUNCTION OF ONE CLASS CAN BE FRIEND TO ANOTHER CLASS
class A{
    public :
    void func(){
        // ...
    }
    void func2(){
        //..
    }
    void func3(){
        //..
    }
};      
class B{
    public :
    friend void A::func();
    friend void A::func2();
}; 

// ******** IF WE WANT TO MAKE ALL FUNCTIONS OF A CLASS 'A' TO BE FRIEND OF CLASS 'B' INSTEAD OF WRITING ALL EXPLICITLY WE CAN DIRECT MAKE CLASS FRIEND
class B{
    friend class A;
};












//  POLYMORPHISM

// Polymorphism: The word polymorphism means having many forms. In simple words, we can define polymorphism as the ability of a message to be displayed in more than one form.
// A person at the same time can have different characteristic. Like a man at the same time is a father, a husband, an employee.
//  So the same person posses different behaviour in different situations. This is called polymorphism.

// An operation may exhibit different behaviours in different instances. The behaviour depends upon the types of data used in the operation.
// C++ supports operator overloading and function overloading.

// Operator Overloading: The process of making an operator to exhibit different behaviours in different instances is known as operator overloading.
// Function Overloading: Function overloading is using a single function name to perform different types of tasks.
// Polymorphism is extensively used in implementing inheritance.
// Example: Suppose we have to write a function to add some integers, some times there are 2 integers, some times there are 3 integers. 
// We can write the Addition Method with the same name having different parameters, the concerned method will be called according to parameters.

//TYPES
// Compile-time polymorphism (Method overloading)
// Run-time polymorphism (Method Overriding)


//                                OPERATOR OVERLOADING ( A WAY TO IMPLEMENT COMPILE TIME POLYMORPHISM)
class complex{
    private:
        int a,b;
    public:
        void set_data(int x,int y){
            a = x;             
            b = y;            
        }
        complex operator +(complex c){  //  ****  we use "operator" keyword to do operator overloading
            complex temp;
            temp.a = a+c.a;   // a and b are attributes of caller object
            temp.b = b+c.b;
            return temp;
        }
};
main(){
    complex c1(2,3);
    complex c2(3,4);
    complex c3;
    //If we have used direct + without operator overloading in class defination then there will be erroe as c1 and c2 are user defined types
    c3 = c1+c2;    // here c1 is caller object and c2 is passed as arguement  can also be written as c1.operator+(c2);
}

//uranary operators can also be overload
//all operator except sizeof and ternary (:?) operator can be overloaded
//>> and << can also be overloaded
//definr one int argument for post order increment (do not need to pass anything) so can compiler can idfferentiate b.w pre and post













//               THIS  POINTER  IN C++

// --> this is a keyword in c++
// -->First of all a  pointer that contains address of an object is called object pointer.
// --> this is an local object pointer present in every instance member function containing the address of caller object.
// -->this pointer cannot be modified
class A{
    private:
    int l,b,h;
    public:
    void set(int x,int y,int z){            // Now the problem is if we  use l,b,h instead of x,y,z in parameters of set method then inside the function
        l = x;                              //we will have to do like l = l; b= b; h = h; which will create problem because now l,b,h are local variables of the function 
        b = y;                              //so it will not l,b,h data members 
        h = z;                              // NOW this POINTER SOLVES THIS PROBLEM AS WE CAN DO this->l = l ; this->b = b;
    }
}













//                             INHERITANCE    

//*** AVAILIABILITY VS ACCESSIBILITY

//It is a process of inheriting properties and behaviours of existing classes into a new classes .
//car example -> 4options - > modify same -> complete different(dry) -> some different(encapsulation) -> inheritance
//syntax
class derieved_class : Visibility_mode Base_class{
    //code......
}

//Types : single , multilevel , mutiple , hierarichal , hybrid

// Constructor And Destructor in Inheritance
// order of contructor => parent -- child      (child constructor is called first but it then first executes parent constructor and then child constructor is executed )
// order of destructor => child -- parent

// METHOD  OVERRIDING
//There is a function in parent class and then there is a function in derieved class with same name and arguements only coding
//inside function is different then it is called method overiding.


// Method Hiding -- > Name is same but argument and coding different.

class A{
    public:
        void f1(){};
        void f2(){};
};

class B:public A{
    void f1(){  }   // Method Overriding
    void f2(int x){  }   // Method Hiding
};
void main(){
    B obj; 
    obj.f1(); 
    obj.f2();
    obj.f2(4);
}
// Here f1 and f2 are called that of derieved class because obj type is B  (*****THIS IS CALLED EARLY BINDING)(IN EARLY BINDING IT SEES TYPE OF OBJECT OR POINTER IF THER IS POINTER)
//if there is no f1 in derieved class then only compiler will look in parent class


//  *** VIRTUAL FUNCTION
// 1> BASE CLASS POINTER
// --->Base class pointer can point to the object of any of its descendant claa.
// --->But its converse is not true.
class A{
    public:
        void f1(){};
        void f2(){};
};

class B:public A{
    void f1(){  } 
    void f2(int x){  }  
};
void main(){
    A * p; A o1;  B o2;
    p = &o2;
    p->f1();          // HERE WE WANT TO RUN F1 OF THE DERIEVED (B) CLASS BUT IT WILL RUN F1 OF A CLASS(PARENT) BECAUSE IT WILL DO EARLY BINDING(AS TYPE OF P IS A)
}               // SO THIS IS THE PROBLEM WITH FUNCTION OVERRIDING WHENEVER WE USE THE POINTER OF THE BASE CLASS
// SO TO SOLVE THIS PROBLEM WE CAN FORCE COMPILER TO DO LATE BINDING  
// TO DO LATE BINDING FOR  A FUNCTION WE CAN USE virtual KEYWORD IN FRONT OF FUNCTION DEFINATION IN BASE CLASS 
//****** in late binding it checks the vtable pointed by the vptr of the object pointed by the pointer of base class  and accordingly runs correct functions


// VPTR AND VTABLE
https://practice.geeksforgeeks.org/problems/what-are-vtable-and-vptr