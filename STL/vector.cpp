#include <bits/stdc++.h>
using namespace std;
#include <vector>


int main(){
    int temp, counter=0;
    string tem;

    // initialising a vector.
    vector<int> vec1 ;

    // entering 10 element to see dynamic increaing size of vector.
    while(counter<11)
    {
        // vector_name.pushback used to add term.
        vec1.push_back(counter);

        // vector_name.size() is used to see size.
        cout << "now size of vector vec1 is :" << vec1.size() << endl;
        counter ++;
    }
    
    // vector_name.capacity() to see the size of the storage space currently allocated to the vector expressed as number of elements.
    cout << "Capacity : " << vec1.capacity();
    
    // vector_name.max_size() to see the maximum number of elements that the vector can hold.
    cout << "Max_Size : " << vec1.max_size();

    // checks if the vector is empty or not
    if (vec1.empty() == false)
        cout << "Vector is not empty"<< endl;
    else
        cout << "\nVector is empty" << endl;


    // Shrinks the vector
    vec1.shrink_to_fit();
    
    
    
    
    
    return 0;
}
