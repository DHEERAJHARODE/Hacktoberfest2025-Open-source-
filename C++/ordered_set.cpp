#include<bits/stdc++.h>
using namespace std;
// creating a function for printing an ordered set:
void print_set(set<int>s){
    for(auto it:s){
        cout<<it<<endl;
    }
}
 
 //creating a function for inserting elements in ordered set:
void insert(set<int> &s,int k){
    s.insert(k);
}

// insertion takes O(logn) time complexity in ordered set
int main(){
    set<int>s;
    int n;
    cout<<"Enter size of set :"<<endl;
    cin>>n;

    // asking for inputs from user: 
    for(int i=0;i<n;i++){
        int k;
        cout<<"Enter element :"<<endl;
        cin>>k;
        insert(s,k);
    }
    cout<<"The ordered set is :"<<endl;
    print_set(s);

    //some functions in ordered sets:

    //1.To Find an element :
    int f;
    cout<<"Enter element to be found: "<<endl;
    cin>>f;
    auto it=s.find(f); //O(logn) Time complexity
    if(it!=s.end()){
        cout<<(*it)<<endl;
    }
    else{
        cout<<"Not found"<<endl;
    }
    //2.To erase an element :

    int l;
    cout<<"Enter element to erased :"<<endl;
    cin>>l;
    auto y=s.find(l);
    if(y!=s.end()){
        s.erase(l);   //O(logn) Time Complexity
    }
    
    else{
        cout<<"Element not present"<<endl;
    }
    cout<<"The set is"<<endl;
    print_set(s);

    //3. Find size of set
    cout<<"The size of map is: "<<s.size()<<endl;
}  