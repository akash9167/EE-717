/*
PROBLEM SOLVING AND PROGRAMING
ASSIGNMENT 
NAME:- AYUSH SHARMA
ROLL:- D-27
*/


#include<iostream>
#include<string.h>

using namespace std;

string s = "ALLIZZWELL";
int s_pos = 0;
char **mat;
int spot_r, spot_c;

bool isFound(int r, int c, int pos)
{
	if(r >= 0 && c >= 0 && mat[r][c] == s[pos]) return true;
	
	else return false;
}

bool backTrack(int r, int c, int s_pos)
{
	int i=0;
	
	if(isFound(r, c, s_pos)==true)
	{
		if(s_pos == s.length()) return true;				//check final state
		
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
	}
	
	else 
	{
		s_pos = s_pos -1;
		return false;
	}
}

int main()
{
	int t,r,c;
	int j, k;
	cin>>t;
	
	for(int i=0; i<t; i++)
	{
		cin>>r;
		cin>>c;
		
		mat = new char *[r];							//memory allocated to rows
		
		for(j=0; j<r; j++)	mat[j] = new char[c];	//memory allocated to columns
		
		for(j=0; j<r; j++)
		{
			char str[c+1]={'\0'};
			cin>>str;
			
			cout<<"\n"<<r<<"\n"<<c;
			
			for(k=0; k<c; k++)
			{
				cout<<"\nYO IN FOR LOOP\n"<<str[k];
				mat[r][k]=str[k];
				cout<<"\nYO ELEMENT INSERTED";
			}
			
		}

		
		j = 0;
		k = 0;
		
		while(j<r && k<c && backTrack == false)		// finding start of the sentence
		{
			if(mat[j][k]==s[0])
			{
				backTrack(r, c, 0);
			}
			j++;
			k++;
		}
		
		for(i = 0 ; i < r ; i++ )
		delete [] mat[i] ;
		delete [] mat ;
		//if(count == 10) cout << "\nYES";
		//count = 0;
	}
}
