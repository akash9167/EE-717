#include<stdio.h>
int main()
{
	char string1[100],string2[100];
	int x=0;
	int i=0;
	int y=0;
	int j=0;
	int count1=0;
	int count2=0;
	int count3=0;
	int tmp = -1;
	
	//creating array of given input
	
	gets(string1);
	gets(string2);
	
	for(x=0; string1[x]!='\0'; x++)
	{
		count1++;
	}
	
	for(x=0; string2[x]!='\0'; x++)
	{
		count2++;
	}
	
	if(count1==count2)
	{
		while(1)
		{
			for(j=0; j < count2 ; j++)
			{
				if(string1[j]==string2[i] && j!=tmp) //checking 
				{
					tmp = j;
					count3++;
					i++;
				}
			}
			if(count3==0) break;
			count3 = 0;
		}
		if(i==count2) printf("yes");
		else printf("no");
	}
	
	else printf("no");
	
	return 0;
}
