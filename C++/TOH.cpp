#include<bits/stdc++.h>
using namespace std;

//tower of HANOI function implementation
void TOH(int n,char A, char B,char C)
{ 
	if(n==1)
	{
		cout<<"Move Disk "<<n<<" from "<<A<<" to "<<C<<endl;
		return;
	}
	
	TOH(n-1,A,C,B);
	cout<<"Move Disk "<<n<<" from "<<A<<" to "<<C<<endl;
	TOH(n-1,B,A,C);
}

//main program
int main()
{ 
	int n;
	
	cout<<"Enter no. of disks:";	
	cin>>n;
	//calling the TOH 
	TOH(n,'A','B','C');
	
	return 0;
}

