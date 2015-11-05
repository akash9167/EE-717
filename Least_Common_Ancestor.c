#include<stdio.h>
#include<stdlib.h>

char * array=NULL;

void add(char c)
{
	
}

int main()
{
	int length, i;
	char element;
	
	scanf("%d",&length);
	
	array=malloc((length+1)*sizeof(char));
	
	for(i=1; i<=length; i++)
	{
		scanf(" %c",element);
		add(element);
	}
}
