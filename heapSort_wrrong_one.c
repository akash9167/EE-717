#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef int * Heap;

void swap(int *A, int a, int b)
{
    int tmp = A[a];
    A[a] = A[b];
    A[b] = tmp;
}

void maxHeapify(Heap h1, int location, int size);

int extractMax(Heap h1, int *sizePtr);

void  buildHeap(Heap h1, int size);

void maxHeapify(Heap h1, int location, int size)
{
	int k=2*location;
    
	if(k+1 <= size && h1[k]<h1[k+1])
   	{
   		k = k+1;
	}
	
	if(h1[location]<h1[k])
	{
		swap(h1,location,k);
	}

	location=location*2;
	if(location<=size/2)
	{
		maxHeapify(h1, location, size);
	}
}

int extractMax(Heap h1, int *sizePtr)
{
	int max = h1[1];
	h1[1]=h1[*sizePtr];
	*sizePtr = *sizePtr-1;
	buildHeap(h1, *sizePtr);	//using maxheapify here is correct one. why ?
	return max;
}

void  buildHeap(Heap h1, int size)
{
	int i;
	for(i=size/2; i!=0; i--)
	{
		maxHeapify(h1, i, size);
	}
}

void heapSort(Heap h1, int N)
{
    int num=N;
    int i;

    buildHeap(h1, N);

    for(i=1; i<=num; i++){
        int val = extractMax(h1, &N);
        h1[num-i+1] = val;
    }
       
}

void printHeap(Heap h1, int size)
{
    int i;
    for(i=1; i<=size; i++){
        printf("%d\n",h1[i]);
    }
}

int main(void)
{
    int N;
    scanf("%d",&N);
    int num=N;
    
    int i;        

    //Allocate 1 more than N and use from 1 to N
    int *h1 = (int *) malloc (sizeof(int) * (N+1));

    for (i=1; i<=N; i++){
        scanf("%d",&h1[i]);
    }
	
	//buildHeap(h1, N);
    heapSort(h1, N);
    printHeap (h1, N);

    return 0;
}
