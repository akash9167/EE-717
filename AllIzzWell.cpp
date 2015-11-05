#include<iostream>
#include<string.h>
#define MAX 100
using namespace std;

string s = "ALLIZZWELL";
int s_pos = 0;
char mat[MAX][MAX]={'\0'};
int ROW=0,COLUMN=0;

bool isFound(int r, int c, int pos)
{
	if((r >= 0 && c >= 0) && (r <= ROW && c <= COLUMN) && mat[r][c] == s[pos]) 
	{
	
		return true;
	}
	
	else return false;
}

bool backTrack(int r, int c, int s_pos)
{
	int i=0;
	
	if(s_pos>=11)
	{
		return false;
	}
	
	if(isFound(r, c, s_pos)==true)
	{
		mat[r][c]='0';
	
		if(s_pos+1 == s.length()) return true;				//check final state
	
		if(backTrack(r,c+1,s_pos+1) == true)			//east
		{
			return true;
		}
		if(backTrack(r+1,c+1,s_pos+1) == true)		//sout-east
		{
			return true;
		}
		if(backTrack(r+1,c,s_pos+1) == true)			//south
		{
			return true;
		}
		if(backTrack(r+1,c-1,s_pos+1) == true)		//south-west
		{
			return true;
		}
		if(backTrack(r,c-1,s_pos+1) == true)			//west
		{
			return true;
		}
		if(backTrack(r-1,c-1,s_pos+1) == true)		//north-west
		{
			return true;
		}
		if(backTrack(r-1,c,s_pos+1) == true)			//north
		{
			return true;
		}
		
		if(backTrack(r-1,c+1,s_pos+1) == true)		//north-east
		{
			return true;
		}
		else
		{
			mat[r][c]=s[s_pos];
			return false;
		}
	}
	
	else 
	{
		s_pos = s_pos -1;
		return false;
	}
}

int main()
{
	int t;
	int j, k;
	cin>>t;
	
	for(int i=0; i<t; i++)
	{
		cin>>ROW;
		cin>>COLUMN;
		
		for(j=0; j<ROW; j++)
		{
		
			for(k=0; k<COLUMN; k++)
				cin>>mat[j][k];
			
			
		}
		
		
		j = 0;
		k = 0;
		bool back = false;
		
		while(j<ROW && k<COLUMN && back == false)		// finding start of the sentence
		{
			if(mat[j][k]==s[0])
			{
				back = backTrack(j, k, 0);
			}
			k++;
			if(k==COLUMN)
			{
				k=0;
				j++;
			}	
		}
		
		if(back == true) cout << "\nYES";
		else cout << "\nNO";
		
		for(j=0; j<ROW; j++)
		{
		
			for(k=0; k<COLUMN; k++)
				mat[j][k]='\0';
			
			
		}
		
	}
}
