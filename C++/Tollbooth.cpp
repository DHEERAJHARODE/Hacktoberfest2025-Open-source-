#include<iostream>
using namespace std;
class TollBooth
{
    int car;
    float amt;

public:
    TollBooth()
    {
        car=0;
        amt=0;
    }

    void paycar()
    {
        car++;
        amt+=50;
    }
    void nopaycar()
    {
        car++;
    }
    void display()
    {
        cout<<"\n Total car= " <<car;
        cout<<"\n Total Amount= " <<amt;

    }

};
int main()
{
    TollBooth obj;
    int choice;
    do
    {
        cout<<"\n\n\n\n";
        cout<<"@@@@  MENU  @@@@";
        cout<<"\n 1:paying car";
        cout<<"\n 2:nonpaying car";
        cout<<"\n 3:display";
        cout<<"\n 4:Exit";
        cout<<"\n Enter choice";
        cin>>choice;

        switch(choice)
        {
            case 1 : obj.paycar(); break;
            case 2 : obj.nopaycar(); break;
            case 3 : obj.display(); break;
            case 4 : cout<<"\n GOOD BYE  "; break;
            default : cout<<"\n Invalid choice";
        }

    }while(choice!=4);
}
