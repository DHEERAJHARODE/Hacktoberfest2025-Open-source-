#include <iostream>
#include <vector>
using namespace std;

//Vector is a dynamic arr , where capacity 
// is alwsys increased by 2n where n = size

int main()
{
 vector <int> v1 {1,2,3};
 
 vector <int> v2;
 
 vector <string> v3(3,"hello");
 
 
 cout<<v3[0]<<endl;
 cout<<v3[1]<<endl;
 cout<<v3[2]<<endl;
 
 cout<<"capacity before adding element in v2 = "<<v2.capacity()<<endl;
 
 cout<<"\nAdding element in v2"<<endl;
 
 v2.push_back(10);
 
 v2.push_back(120);
 
 cout<<"added  Element ="<<v2[0]<<endl;
 
 cout<<"capacity after adding element in v2 ="<<v2.capacity()<<endl;
 v2.pop_back();//for popping element
 cout<<"elements in vector "<<v1.size()<<endl;//tells xount of element in vector
    
    
cout<<"pos in v1="<<v1.at(2)<<endl;//indexer


cout<<"elements in v1 at firdt ="<<v1.front()<<endl;

cout<<"elements in v1 at back ="<<v1.back()<<endl;
vector <int> v7;

for(int i =0 ;i<=9;i++)
{
  v7.push_back(10*(i+1));
}


for(int i =0;i<v7.size();i++)
{
  cout<<v7[i]<<endl;
}

//now we will use interator to add value in the middle

cout<<"\nVECTOR V7\n";

vector <int>::iterator it=v7.begin();
v7.insert(it+3,786);

cout<<"\n after adding element 786\n";

for(int i =0;i<v7.size();i++)
{
  cout<<v7[i]<<endl;
}


}

