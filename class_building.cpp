#include<iostream>
// #include<bits/stdc++.h>

using namespace std;

class Employee {
    public:
    string Name;
    string Company;
    int Age;

    void Introduce(){
        cout<<"Name - "<<Name<<endl;
        cout<<"Comapany - "<<Company<<endl;
        cout<<"Age - "<<Age<<endl;
    }

};

int main(){

    int number;
    Employee employee1;
    employee1.Name="Adwait";
    employee1.Company="IAS";
    employee1.Age=21;     

    employee1.Introduce();

}
