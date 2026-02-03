#include<iostream>
#include<math.h>

using namespace std;

int main(){
	double q,alpha,x,y,a,b,key;
	cout<<"Enter q,Xa,Xb and alpha\n";
	cin>>q>>a>>b>>alpha;
	
	x = pow(alpha,a);
	x = fmod(x,q);
	cout<<"Ya = "<<x<<endl;
	
	y = pow(alpha,b);
	y = fmod(y,q);
	cout<<"Yb = "<<y<<endl;
	
	key = pow(x,b);
	key = fmod(key,q);
	cout<<"Key = "<<key;
	
}
