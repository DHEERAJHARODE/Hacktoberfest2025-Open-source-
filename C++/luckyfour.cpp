#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	int count=0;
	while(t--){
	    int a,rem,count=0;
	    cin>>a;
	    while(a){
	    rem= a%10;
	    if(rem==4 || a==4){
	        count++;
	    }
	    a=a/10;
	    }
	    cout<<count<<endl  ;
	  
	}
	
	return 0;
}
