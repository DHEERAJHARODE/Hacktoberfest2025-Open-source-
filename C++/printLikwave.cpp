#include<iostream>
using namespace std;

int main(){
     int arr[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    for(int cols=0;cols<3;cols++){
        if(cols%2==0){
            for(int rows=0;rows<3;rows++){
                cout<<arr[rows][cols]<<" ";
            }
        }
        else{
            for(int rows=2;rows>=0;rows--){
                cout<<arr[rows][cols]<<" ";
            }
        }
        
        cout<<endl;
    }

}