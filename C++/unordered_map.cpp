#include<bits/stdc++.h>
using namespace std;
// creating a function for printing an unordered map:
void print_map(unordered_map<int,int>m){
    for(auto it:m){
        cout<<it.first<<" "<<it.second<<endl;
    }
}
 
 //creating a function for inserting elements in unordered map:
void insert(unordered_map<int,int> &m,int k,int v){
    m.insert({k,v});
}

// insertion takes O(1) time complexity in unordered maps
int main(){
    unordered_map<int,int>m;
    int n;
    cout<<"Enter size of unordered map :"<<endl;
    cin>>n;

    // asking for key value pairs from user: 
    for(int i=0;i<n;i++){
        int k,v;
        cout<<"Enter key :"<<endl;
        cin>>k;
        cout<<"Enter Value :"<<endl;
        cin>>v;
        insert(m,k,v);
    }
    cout<<"The unordered map is :"<<endl;
    print_map(m);

    //some functions in unordered maps:

    //1.To Find an element :
    int f;
    cout<<"Enter element to be found: "<<endl;
    cin>>f;
    auto it=m.find(f); //O(1) Time complexity
    if(it!=m.end()){
        cout<<(*it).second<<endl;
    }
    else{
        cout<<"Not found"<<endl;
    }
    //2.To erase an element :

    int l;
    cout<<"Enter element to erased :"<<endl;
    cin>>l;
    auto y=m.find(l);
    if(y!=m.end()){
        m.erase(l);   //O(1) Time Complexity
    }
    
    else{
        cout<<"Element not present"<<endl;
    }
    cout<<"The map is"<<endl;
    print_map(m);

    //3. Find size of map
    cout<<"The size of map is: "<<m.size()<<endl;
}  