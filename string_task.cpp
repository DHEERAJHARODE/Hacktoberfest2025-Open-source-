#include<iostream>
using namespace std;
int main()
{
	int i,j,temp,l;
string s;
cin>>s;
l=s.length();
for(i=0;i<l;i++)
{
	if(s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'||s[i]=='Y'||s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='y')
	{
		for(j=i;j<l;j++)
	s[j]=s[j+1];
	l--;
	i--;	
	}
}
for(i=0;i<l;i++)
{
int a=s[i];
if(a>=65&&a<=90)
a=a+32;
s[i]=a;	
}
for(i=0;i<l;i++)
{
cout<<"."<<s[i];	
}	
}
