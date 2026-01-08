#include<iostream>
using namespace std;
int facto(int number){
	
 int fact=1;
 for(int i=2;i<=number;i++){
 if(number>=0){
 fact*=i;
 }
 }
 return fact;
}
int main(){
 cout<<"Enter a positive integer ";
 int num;
 cin>>num;
 int fact;
 fact=facto(num);
 if(num<0){
	 cout<<"Invalid input!!"<<endl;
 }
 else
 cout<<"Factorial of the postive integer is ";
 cout<<fact<<endl;

}