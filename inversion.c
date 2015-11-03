#include <stdio.h>
#include <stdlib.h>

int inversions(int *A, int N);
//void mergeSort(int *A,int low,int mid,int high);
//void partition(int *A,int low, int high);

int inv=0;

void mergeSort(int *A,int low,int mid,int high)
{
	int i,m,k,l;
    int *temp=(int*)malloc(1000000*sizeof(int));

    l=low;
    i=low;
    m=mid+1;

    while((l<=mid)&&(m<=high))
	{
         if(A[l]<=A[m])
		 {
             temp[i]=A[l];
             l++;
         }
         else
		 {
             temp[i]=A[m];
             m++;
             
             inv=inv+mid+1-l;
         }
         i++;
    }

    if(l>mid)
	{
         for(k=m;k<=high;k++)
		 {
             temp[i]=A[k];
             i++;
         }
    }
    else
	{
         for(k=l;k<=mid;k++)
		 {
             temp[i]=A[k];
             i++;
         }
    }
   
    for(k=low;k<=high;k++)
	{
         A[k]=temp[k];
    }
}

void partition(int *A,int low,int high)
{

    int mid;
	//printf("\nYO PARTITION");
    if(low<high)
	{
         mid=(low+high)/2;
         partition(A,low,mid);
         partition(A,mid+1,high);
         mergeSort(A,low,mid,high);
    }
}


int inversions(int *A, int N)
{
	int low = 0;
	int high = N-1;
	partition(A,low,high);
	return inv;
}


int main(void)
{
    int N, *A;
    int i;
    scanf("%d",&N);

    A = (int *) malloc(sizeof(int)*N);
    for(i=0; i<N; i++){
        scanf("%d",&A[i]);
    }
    int count = inversions(A,N);
    printf("%d",count);
    return 0;
}
