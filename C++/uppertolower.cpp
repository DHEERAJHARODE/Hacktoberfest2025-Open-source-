#include<stdio.h>
int main()
{
	char a[100],b[100];
	int i,j;
	printf("enter the character in upper case \n");
	gets(a);
	for(i=0;a[i]!='\0';i++)
	{
		b[i]=a[i]+32;
	}
	printf("%s",b);

/*	for(j=0;j<i;j++)
	{
		
	}*/
}
