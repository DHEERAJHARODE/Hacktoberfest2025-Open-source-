//:::::::::::::::::::::::::VECTORS:::::::::::::::::::::::::::::::::

//READ MORE AT : https://www.geeksforgeeks.org/vector-in-cpp-stl/
//READ MORE AT : https://www.cplusplus.com/reference/vector/vector/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{

    //////////////////////////////////////////////////////
    //declare
    vector<int> v1;

    vector<int> a(5, 1); //dump all with 1
    vector<int> b(5, 0); //dump all with 0

    vector<int> a1{10, 11, 12}; //assign directly
    vector<int> b1{1, 2};

    //////////////////////////////////////////////////////
    //SWAP
    // before
    //     a=[1,1,1,1,1]
    //     b=[0,0,0,0,0]
    a.swap(b);
    // after
    //     a=[0,0,0,0,0]
    //     b=[1,1,1,1,1]

    cout << "\nAfter Swap \nVector 1: ";
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << " ";

    cout << "\nAfter Swap \nVector 2: ";
    for (int i = 0; i < b.size(); i++)
        cout << b[i] << " ";

    /////////////////////size diff swap///////////////////////
    a1.swap(b1);

    cout << "\nAfter Swap \nVector A1: ";
    for (int i = 0; i < a1.size(); i++)
        cout << a1[i] << " ";

    cout << "\nAfter Swap \nVector b1: ";
    for (int i = 0; i < b1.size(); i++)
        cout << b1[i] << " ";

    //////////////////////////////////////////////////////////////
    //input
    cout << endl;
    cout << "INPUT VALUES :" << endl;
    for (int i = 1; i <= 5; i++)
    {
        int x;
        cin >> x;
        v1.push_back(x);
    }

    ///////////////////////////////////////////////////////////////

    //ALGORITHMS
    cout << "HEY HEY HEY welcome to algorithm library ::::" << endl;
    //ouput
    sort(v1.begin(), v1.end()); //sortfunction
    cout << "::::: Printing SORTED from algorithms ::::::" << endl;

    for (int i = 0; i < 5; i++)
    {
        cout << v1[i] << " ";
    }

    //////////////////////////////////////////////////////////////////
    //ouput
    cout << endl
         << "::::: using [i] loop ::::::" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << v1[i] << " ";
    }

    //output using ITR
    cout << endl
         << "::::: using ITR ::::::" << endl;
    for (auto i = v1.end() - 1; i >= v1.begin(); --i)
    {
        cout << *i << " ";
    }

    //////////////////////////////////////////////////////////////////////
    //SIZES
    cout << endl;
    cout << "Size : " << v1.size(); //5

    cout << "\nCapacity : " << v1.capacity(); //8

    //shrinking
    v1.shrink_to_fit(); //8-----5

    cout << "\nCapacity : " << v1.capacity(); //5

    cout << "\nMax_Size : " << v1.max_size();

    cout << endl
         << v1.empty();

    if (v1.empty() == 0)
        cout << "\nVector is not empty";
    else
        cout << "\nVector is empty";

    //////////////////////////////////////////////////////////////////////
    //POSITIONS:
    cout << "\n Vector at position 0 : " << v1[0];
    cout << "\n Vector at position 0 : " << v1.front();
    cout << "\n Vector at last : " << v1.back();
    cout << "\n Vector @ at the POS 2: " << v1.at(2);
    cout << endl;

    /////////////////////////////////////////////////////////////////////
    //pop_back
    cout << endl
         << "::::: pop_back ::::::" << endl;
    for (int i = 4; i >= 0; i--)
    {
        cout << v1[i] << "deleting" << endl;
        v1.pop_back();
        cout << v1.size() << endl;
    }

    ///////////////////////////////////////////////////////////////////////
    //clearing vector
    v1.clear();

    if (v1.empty() == 0)
        cout << "\nVector is not empty";
    else
        cout << "\nVector is empty";

    /////////////////////////////////////////////////////////////////////

    return 0;
}