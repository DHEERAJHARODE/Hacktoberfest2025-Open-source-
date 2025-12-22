#include <iostream>
#include<deque>
using namespace std;

int main()
{
    deque<int> d;
    d.push_back(1);
    d.push_front(2);
    for (int i:d)
    {
      cout<<i<<" ";
    }
    d.pop_back();
}
