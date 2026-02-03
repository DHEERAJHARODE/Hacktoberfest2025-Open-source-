#include<bits/stdc++.h>
using namespace std;
// creating a function for printing an ordered map:
void print_map(map<int,int>m){
    for(auto it:m){
        cout<<it.first<<" "<<it.second<<endl;
    }
}
 
 //creating a function for inserting elements in ordered map:
void insert(map<int,int> &m,int k,int v){
    m.insert({k,v});
}

// insertion takes O(logn) time complexity in unordered maps
int main(){
    map<int,int>m;
    int n;
    cout<<"Enter size of map :"<<endl;
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
    cout<<"The ordered map is :"<<endl;
    print_map(m);

    //some functions in ordered maps:

    //1.To Find an element :
    int f;
    cout<<"Enter element to be found: "<<endl;
    cin>>f;
    auto it=m.find(f); //O(logn) Time complexity
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
        m.erase(l);   //O(logn) Time Complexity
    }
    
    else{
        cout<<"Element not present"<<endl;
    }
    cout<<"The map is"<<endl;
    print_map(m);

    //3. Find size of map
    cout<<"The size of map is: "<<m.size()<<endl;
}  