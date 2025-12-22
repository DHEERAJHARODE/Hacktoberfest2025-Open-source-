#include <iostream>
#include<math.h>
using namespace std;

int main()
{                       // it is leetcode problem's solution for find unique number
    int size;
    int ans=0;
    cin>>size;
    int arr[size];
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    for(int i=0;i<size;i++)
    {
        ans=ans^arr[i];
    }
    return ans; 
}       