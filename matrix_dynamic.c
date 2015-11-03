#include<stdlib.h>
#include<stdio.h>

int main()
{
	int n, l, i, j, k;
	unsigned long q;
	unsigned long *sizes = NULL;
	unsigned long n1 = n*n;
	scanf("%d",&n);
	
	
	sizes = malloc((n+1)*sizeof(long));
	unsigned long **store = (unsigned long**)malloc((n+1)*sizeof(unsigned long*));
	unsigned long **k_mat = (unsigned long**)malloc((n+1)*sizeof(unsigned long*));
	
	for(i=0; i<=n; i++)
	{
		int p;
		scanf("%d",&p);
		sizes[i]=p;
	}
	
	for(i=0; i<n+1; i++)
	{
		store[i]=(unsigned long*)malloc((n+1)*sizeof(long));
		k_mat[i]=(unsigned long*)malloc((n+1)*sizeof(long));
	}
	
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			store[i][j]=0;
			k_mat[i][j]=0;
		}
	}
	
	for(l=2; l<=n; l++)
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
				//printf("YO_inside loop 3\n");
				q = store[i][k]+store[(k+1)][j]+sizes[i-1]*sizes[k]*sizes[j];
				
				/*printf("Before\nQ: %d\n",q);
				printf("Store[i][j]: %d\n",store[i][j]);
				printf("k_mat[i][j]: %d\n",k_mat[i][j]);
				*/
				if(q<store[i][j]) 
				{
					store[i][j]=q;
					k_mat[i][j]=k;
					printf("Store[%d][%d]: %d\n",i,j,store[i][j]);
					printf("k_mat[%d][%d]: %d\n",i,j,k_mat[i][j]);
				}			
			}
		}
	}
	printf("%d",k_mat[1][n]);
	
	for(i=0; i<n; i++)
	{
		free(store[i]);
		free(k_mat[i]);
	}
	free(store);
	free(k_mat);
	free(sizes);
}
