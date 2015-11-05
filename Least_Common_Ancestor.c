#include<stdio.h>
#include<stdlib.h>

char * array=NULL;

void add(char c, int count)
{
	printf("Error in function\n");
	if(array[count]=='0')
	{
		printf("Error in condition\n");
		array[count]=c;
		return;
	}
	
	else if(c>array[count])
	{
		add(c, 2*count+1);
	}
	
	else if(c<array[count])
	{
		add(c, 2*count);
	}
}

int main()
{
	int length, i;
	char element;
	
	scanf("%d",&length);
	
	array=malloc((length+1)*sizeof(char));
	
	for(i=0; i<=length; i++)
	{
		array[i]='0';
	}
	
	for(i=1; i<=length; i++)
	{
		printf("\ninside loop\n");
		scanf(" %c",element);
		printf("\nelement read\n");
		add(element, 1);
	}
}
