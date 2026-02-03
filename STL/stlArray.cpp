#include<bits/stdc++.h>
#include<array>
using namespace std;

int main()
{
    //Initializing the array type with size
    array<int,4> a = {1,2,3,4};

    //taking the size of the array
    int size = a.size();

    for(int i=0;i<size;i++)
    {
        cout<<a[i]<<endl;
    }

    cout<<"The element at the second index of the array is: "<<a.at(2)<<endl;

    cout<<"The first element of the array is "<<a.front()<<endl;
    cout<<"The last element of the array is "<<a.back()<<endl;

}