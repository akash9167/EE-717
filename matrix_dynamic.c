#include<stdlib.h>
#include<stdio.h>

unsigned long **k_mat;
int *divisions;
int n;
int count = 0;

void print(int i, int j)
{
	
	int k = k_mat[i][j]; 
	
	//printf("COUNT IS: %d\n",count);
	
	//if(k==0) return;
	
	/*if(count == n-1) 
	{
		printf("Condition: count == n-1\n");
		return;
	}
	*/
	if(j==i+1 || i==j-1) 
	{
		printf("\nCondition: j==i+1 || i==j-1\n");
		return;
	}
	
	else if( k==i)
	{
		printf("\nCondition: k==i\n");
		printf("K IS: %d\n",k);
		
		divisions[count]=k;
		
		count++;
		print(k+1,n);
	}
	
	else if( k==n)
	{
		k=k-1;
		printf("\nCondition: k==n\n");
		printf("K IS: %d\n",k);
		
		divisions[count]=k;
		count++;
		print(i,k);
	}
	
	else if(k>i&&k<j)
	{
		printf("\nCondition: k>i && k<j\n");
		printf("K IS: %d\n",k);
		
		divisions[count]=k;
		count++;
		print(i,k);
		print(k+1,n);
	}
	
	
}

int main()
{
	int l, i, j, k;
	unsigned long q;
	unsigned long *sizes = NULL;
	//unsigned long n1 = n*n;
	unsigned long **store;
	
	scanf("%d",&n);

	sizes = malloc((n+1)*sizeof(long));
	divisions = malloc(n*sizeof(int));
	
	store = (unsigned long**)malloc((n+1)*sizeof(unsigned long*));
	k_mat = (unsigned long**)malloc((n+1)*sizeof(unsigned long*));
	
	for(i=0; i<=n; i++)				
	{
		int p;
		scanf("%d",&p);
		sizes[i]=p;
		divisions[i]=0;
	}
	
	for(i=0; i<n+1; i++)
	{
		store[i]=(unsigned long*)malloc((n+1)*sizeof(long));
		k_mat[i]=(unsigned long*)malloc((n+1)*sizeof(long));
	}
	
	for(i=0; i<=n; i++)
	{
		for(j=0; j<=n; j++)
		{
			store[i][j]=0;
			k_mat[i][j]=0;
		}
	}
	
	for(l=2; l<=n; l++)					//dynamic part
	{
		//printf("YO_inside loop1\n");
		for(i=1; i<=n-l+1; i++)
		{
			j=i+l-1;
			//printf("YO_inside loop2\n");
			store[i][j]=9999999;
			//printf("YO_after making value infinite\n");
			for(k=i; k<j; k++)
			{
				
				q = store[i][k]+store[(k+1)][j]+sizes[i-1]*sizes[k]*sizes[j];
				/*
				printf("\nsizes[j] is: %d\n",sizes[j]);
				printf("Before\nQ: %d\n",q);
				printf("Store[i][k]: %d\n",store[i][k]);
				printf("Store[k+1][j]: %d\n",store[k+1][j]);
				*/
				if(q<store[i][j]) 				
				{
					store[i][j]=q;					//storing q values for use in next iterations
					k_mat[i][j]=k;					//storing k values
					printf("Store[%d][%d]: %d\n",i,j,store[i][j]);
					printf("k_mat[%d][%d]: %d\n",i,j,k_mat[i][j]);
				}			
			}
		}
	}
	
	print(1,n);
	
	/*int seq;
	for(i=0; i<=1; i++)
	{
		seq = k_mat[1][n];
		if(i==0) printf("%d ",k_mat[1][n] );
		
	}
	*/
	for(i=0; divisions[i]!=0 && i<=n; i++)
	{
		printf("\nDivisions at: %d\n",divisions[i]);
		//printf("\n: {%d, %d}\n",divisions[i][1],divisions[i][2]);
	}
		printf("\ncount is: %d\n",count);
	for(i=0; i<n; i++)
	{
		free(store[i]);
		free(k_mat[i]);
	}
	free(divisions);
	free(store);
	free(k_mat);
	free(sizes);
}
