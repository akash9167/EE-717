#include<stdio.h>
#include<string.h>
int main()
{
	char main_string[40],string1[20],string2[20];
	char chr;
	int x=0,position;
	int i=0;
	int y=0;
	int j=0;
	int count=0;
	
	//creating array of given input
	
	gets(main_string);
	int length = strlen(main_string);
	for(x; x<19; x++)
	{
		if(main_string[x] == ' ')
		{
			position = x+1;
			break;
		}
		else
		{
			string1[x] = main_string[x];
			position = 20;
		}
	}
	
	for(y; y<19; y++)
	{
		if(position+y == length || main_string[position+y] == ' ')
		break;
		else
		string2[y] = main_string[position+y];
	}
	
	//identifying consecutive same characters
	i = 0;
	for(j = 0; j<position ; j++)
	{		
		if(string2[i]==string1[j] ) 
		{
			i++;
			count++;					//incrementing count by 1 if match found
			if(string2[i]=='\0'  ) 
			{
				break;					//keeping y in range
			}
		}
		else 
		{
			i = 0;
			count = 0;
		}
	}

	if(count==y)						//if count == number of characters in string2 then print position of first character
	{
		printf("%i\n",(j-y+1));
	}
	else printf("%i\n",-1);

	return 0;
}
