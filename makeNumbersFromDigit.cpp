#include<iostream>
using namespace std;
int main() {
	int p=1;
	int n; 
	cin>>n;
	int sum=0;
	for(int i=1; i<=n; i++){
		int dig;
		cin>>dig;
		sum=sum+dig*p;
		p=p*10;
	}
	cout<<sum<<endl;
	return 0;
}
