#include<bits/stdc++.h>
using namespace std;

int main(){
    
    //we got 2 types of set 1.Ordered set 2.Unordered set
    //Here unique values are stored
    //The values are stored in ascending or descending order if we use ordered set

    //definition  of sets...
    set<int> sam;

    //Insertion of values in set..
    sam.insert(10);
    sam.insert(90);
    sam.insert(20);

    //Printing of set values using FOr Each loop

    //after printing as we will be getting our result in the ascending order rather than printing
    //it in the order we inserted into the set...
    for(auto &n: sam){
        cout<<n<<endl;
    }

    //FUNCTIONS RELATED TO SETS...
    //1.Begin & End...
    //Begin will return an iterator pointing to the first element
    //End will return an iterator pointing to the last element
    //2.Size- It will return the size of set..
    //3.Empty-Returns an integer value stating the set is empty or not..

    //printing using begin and end..
    for(auto itr = sam.begin();itr!= sam.end();itr++){
        cout<<*itr<<endl;
    }
    
    cout<<"Size of the set: "<<sam.size()<<endl;

    cout<<sam.empty();
    
    //Removing of Elementes..
    //1.Clear 2.erase
    //clear will remove all elements from the set..
    //using erase we delete specific element of the set..
    sam.erase(10);
    
    //sam.clear();
    cout<<*sam.begin();//Its 20;

    return 0;

}

