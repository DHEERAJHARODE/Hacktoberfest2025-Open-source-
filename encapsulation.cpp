#include<iostream>
// #include<bits/stdc++.h>

using namespace std;

class Employee {

private:
    string Name;
    string Company;
    int Age;

public:
    void setName(string name){
        Name=name;
    }
    string getName(){
        return Name;
    }

    void setAge(int age){
        if(age>=18){
            Age=age;
        }
    }   
    int getAge(){
        return Age;
    }

    void setCompany(string company){
        Company=company;
    }
    string getCompany(){
        return Company;
    }

    void Introduce(){
        cout<<"Name - "<<Name<<endl;
        cout<<"Comapany - "<<Company<<endl;
        cout<<"Age - "<<Age<<endl;
    }

    Employee(string name, string company, int age){
        Name=name;
        Company=company;
        Age=age;
    }

};

int main(){

    Employee employee1=Employee("Adwait","Google",21);
    employee1.Introduce();

    Employee employee2=Employee("Tejas","Amazon",21);
    employee2.Introduce();

    employee1.setAge(20);
    cout<<employee1.getName()<<" is "<<employee1.getAge()<<" Years Old..";

}
