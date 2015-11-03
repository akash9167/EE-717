#include<stdlib.h>
#include<stdio.h>

void change(int a[])
{
	a[2]=0;
}

int main()
{
	int i;
	int *a=(int*)malloc(4*sizeof(int));
	for(i=0; i<4; i++)
	{
		a[i]=i;
	}
	
	//change(a);
	printf("%d",a[12]);
}
