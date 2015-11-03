#include<stdio.h>
#include<stdlib.h>

int main()
{
	int v, e, i, j, x, y;
	
	scanf("%d",v);
	scanf("%d",e);
	
	int *arr=(int *)malloc(2*v*sizeof(int));
	
	for(i=0; i<2*v; i++) 
		arr[i]=-1;
	
	for(i=0; i<e; i++)
	{
		scanf("%d",x);
		scanf("%d",y);
		
	}
}
