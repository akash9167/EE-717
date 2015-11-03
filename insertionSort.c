#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void insertionSort(int *A, int size)
{
	int i,j,p_smallest,tmp;
	p_smallest=0;
	for(i=0; i<size-1; i++)
	{
		
		p_smallest=i;
		for(j=i+1; j<size; j++)
		{
			if(A[i]>A[j])
			{
				if(A[p_smallest]>A[j])	//comparing whether it is the smallest element in remaining array & then swapping it
				{
					p_smallest=j;
				}
			}
		}
		tmp=A[i];
		A[i]=A[p_smallest];
		A[p_smallest]=tmp;
	}
}

void printArray(int *A, int size)
{
    int i;
    for(i=0; i<size; i++){
        printf("%d\n",A[i]);
    }
}

int main(void)
{
    int N;
    scanf("%d",&N);
 
    
    int i;        
    int *A = (int *) malloc (sizeof(int) * (N));

    for (i=0; i<N; i++){
        scanf("%d",&A[i]);
    }
    
    insertionSort(A, N);
    printArray (A, N);

    return 0;
}
