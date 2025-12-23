#include<iostream>
using namespace std;
int main()
{
	int n,i,j;
	cin>>n;
	string s[n];
	int key[n];
	for(i=0;i<n;i++)
		key[i]=0;
	for(i=0;i<n;i++)
	cin>>s[i];
	for(i=0;i<n;i++)
	{
		if(key[i]==0)
		{
			int k=0;
			for(j=i;j<n;j++)
			{
				if(s[i]==s[j])
				{
					key[j]=k;
					k++;
				}
			}
		}
	}
	for(i=0;i<n;i++)
	{
		if(key[i]==0)
		cout<<"OK"<<endl;
		else
		cout<<s[i]<<key[i]<<endl ;
	}
}
