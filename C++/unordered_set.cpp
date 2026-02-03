#include<bits/stdc++.h>
using namespace std;
// creating a function for printing an unordered set:
void print_set(unordered_set<int>s){
    for(auto it:s){
        cout<<it<<endl;
    }
}
 
 //creating a function for inserting elements in unordered set:
void insert(unordered_set<int> &s,int k){
    s.insert(k);
}

// insertion takes O(1) time complexity in unordered sets
int main(){
    unordered_set<int>s;
    int n;
    cout<<"Enter size of unordered set :"<<endl;
    cin>>n;

    // asking for elements from user: 
    for(int i=0;i<n;i++){
        int k;
        cout<<"Enter element :"<<endl;
        cin>>k;
        insert(s,k);
    }
    cout<<"The unordered set is :"<<endl;
    print_set(s);

    //some functions in unordered set:

    //1.To Find an element :
    int f;
    cout<<"Enter element to be found: "<<endl;
    cin>>f;
    auto it=s.find(f); //O(1) Time complexity
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
        s.erase(l);   //O(1) Time Complexity
    }
    
    else{
        cout<<"Element not present"<<endl;
    }
    cout<<"The map is"<<endl;
    print_set(s);

    //3. Find size of map
    cout<<"The size of map is: "<<s.size()<<endl;
}  