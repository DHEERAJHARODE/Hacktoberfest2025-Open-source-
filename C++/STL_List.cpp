#include <iostream>
#include <list>

using namespace std;

//list , sequential ,Front to back 
//back to front

int main()
{
  
  list <int> l1{1,2,3,4,5,6,7,8,9,10};
  list <string> l2{ "sam","usi""shh","iwjw"};
 
  list <int>::iterator it=l1.begin();
  
  //priting elements of list l1
  
  while(it!=l1.end())
  {
    cout<<*it<<endl;
    it++;
  }
  printf("\npriting pushed elements\n");
  
  l1.push_back(888);
  l1.push_front(910);
  cout<<"\n";
  it=l1.begin();
 
  while(it!=l1.end())
  {
    cout<<*it<<endl;
    it++;
  }
   
   printf("\npriting  elements after popping\n");
    it=l1.begin();
  l1.pop_back();
  
  // l1.pop_front();
 while(it!=l1.end())
  {
    cout<<*it<<endl;
    it++;
  }
    
    
    
 l1.remove(4);
 cout<<"\nAfter removing  4 \n";
  
  it=l1.begin();
  
  while(it!=l1.end())
  {
    cout<<*it<<endl;
    it++;
  }
  
  
  cout<<"\nAfter Clearing\n";
  
  
  
  
  
  
  
    
}
