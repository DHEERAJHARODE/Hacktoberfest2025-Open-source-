#include<iostream>
// #include<bits/stdc++.h>

using namespace std;

class abstractEmployee{
    virtual void AskForPromotion()=0;
};

class Employee: abstractEmployee{
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

    void AskForPromotion(){
        if(Age>30){
            cout<<"Promoted"<<endl;
        }
        else{
            cout<<"Get older than 30 "<<Name<<endl;
        }
    }
};


int main(){

    Employee employee1=Employee("Adwait","Google",21);

    Employee employee2=Employee("Tejas","Amazon",21);

    employee1.setAge(32);
    employee1.AskForPromotion();
    employee2.setAge(31);
    employee2.AskForPromotion();

}
