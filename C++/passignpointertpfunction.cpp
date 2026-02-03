#include<iostream>
using namespace std;
void increment(int *aptr)
{
    *aptr++;

}
int main()
{
int a=2;
int *aptr=&a;
increment(&a);
cout<<a<<endl;
}
