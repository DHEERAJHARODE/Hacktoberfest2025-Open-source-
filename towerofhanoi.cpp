#include<bits/stdc++.h>
using namespace std;

void towerOfHanoi(int disk,char x,char y,char z){
    if(disk==1){
        cout<<"Move disk from"<<" "<<x<<" "<<"to"<<" "<<y<<endl;
        return;
    }
    towerOfHanoi(disk-1,x,z,y);
    cout<<"Move disk from"<<" "<<x<<" "<<"to"<<" "<<y<<endl;
    towerOfHanoi(disk-1,z,y,x);
}

int main(){
    int disc;
    cout<<"Enter the number of discs: ";
    cin>>disc;
    towerOfHanoi(disc,'A','C','B');
    return 0;
}