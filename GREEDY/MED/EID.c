#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int compare(const void *a,const void *b)
{
        return (*(int *)a - *(int *)b);
}

int main(void) {
	int t;
	scanf("%d",&t);
	while(t--)
	{
	        int n;
	        scanf("%d",&n);
	        int v[n];
	        for(int i=0;i<n;i++)
	        {
	                scanf("%d",&v[i]);
	        }
	        int min=INT_MAX;
	        qsort(v,n,sizeof(int),compare);
	        for(int i=0;i<n;i++)
	        {
	                if((v[i+1]-v[i])<min)
	                {
	                        min = v[i+1]-v[i];
	                }
	        }
	        printf("%d\n",min);
	        
	}
	return 0;
}
