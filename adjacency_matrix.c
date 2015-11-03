#include<stdio.h>
#include<stdlib.h>

int main()
{
	 int r, e, i, j, u, v;
 	
 	scanf("%d",&r);
 	scanf("%d",&e);
 	
    int **adj_mat = (int **)malloc(r * sizeof(int *));
    for (i=0; i<r; i++)
         adj_mat[i] = (int *)malloc(r * sizeof(int));
 
    for (i = 0; i <  r; i++)
    {
    	for (j = 0; j < r; j++)
        	adj_mat[i][j] = 0;
	}
 
    for (i = 0; i < e; i++)
    {
    	scanf("%d",&u);
    	scanf("%d",&v);
    	adj_mat[u][v] = 0;
    	adj_mat[v][u] = 0;
	}  
    
    
 
   return 0;
}
