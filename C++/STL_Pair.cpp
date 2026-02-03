#include <iostream>
#include <string.h>
using namespace std;

class Student
{
  private:
    int rno;
    string name;
  public:
    void setdata(int r,string n) 
    {
      rno=r;
      name=n;
    }
    
    void showdata()
    {
      cout<<"rno="<<rno<<endl;
      cout<<"name="<<name<<endl;
      
    }
};

int main()
{
 
 pair <string,int> p1;
 
 pair <string,string> p2;
 
 
 pair <string,float> p3;
 
 
pair <int,Student> p4;

    
p1=make_pair("Sam",23);

p2=make_pair("Sam","jones");


p3=make_pair("Sam",23.2);


Student s1;
s1.setdata(1,"rao");


p4=make_pair(1,s1);

//mak3 pair end


//printing starts

 cout<<"\n Pair 1\n";
 cout<<p1.first<<"---"<<p1.second;
 
 
 
 cout<<"\n Pair 2\n";
 cout<<p2.first<<"---"<<p2.second;
 
 
 cout<<"\n Pair 3\n";
 cout<<p3.first<<"---"<<p3.second;
 
 
 cout<<"\n Pair 4\n";
 
 
 cout<<p4.first;
 
 Student s2=p4.second;
 s2.showdata();

}

