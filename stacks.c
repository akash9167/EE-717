#include<stdio.h>
#include<stdlib.h>

int *array = NULL;
int arraySize=0;

char opNames[4][8] = {"push","pop","peek","isEmpty"};

void init(int num)
{
	int i;
	arraySize = num;
	array = malloc((num+2)*sizeof(int));
	for(i=0; i<num; i++)
	{
		array[i]=-1;
	}
	array[num]=0;		//storing sizeof stack 0
	array[num+1]=0;		//storing sizeof stack 1
}
void cleanup()
{
	free(array);
}
int push(int stack, int val)
{
	int i=0;
	int j=0;
	
	if(stack==0)
	{
		while(array[i] != -1 && i<=arraySize)
		{
			i++;
		}
		if(i >= arraySize) return -1;
		else
		{
			array[i]=val;
			array[arraySize] = array[arraySize]+1;
			//printf("Size of stack 0:");
			//printf("%i\n",array[arraySize]);
			return 1;
		}
	}
	
	if(stack==1)
	{
		while(array[arraySize-j-1] != -1 && arraySize-j-1 >= 0 )
		{
			j++;
			//printf("ELement at arraySize-j-1:");
			//printf("%i\n",array[arraySize-j-1]);
			//printf("arraySize-j-1:");
			//printf("%i\n",arraySize-j-1);
		}
		if(j == arraySize)
		{
			return -1;
		}
		else
		{
			array[arraySize-j-1]=val;
			array[arraySize+1]+=1;
			//printf("%i\n",array[arraySize-j-1]);
			//printf("%i\n",arraySize-j-1);
			return 1;
		}
	}
}

int pop(int stack)
{	
	int ret;
	if(stack==0)
	{
		if(array[arraySize]==0)
		{
			ret = -1;
		}
		
		else
		{
			ret = array[array[arraySize]-1];
			array[array[arraySize]-1] = -1;					//updating array with -1 after popping
			array[arraySize]+=-1;
		}
	}
	
	if(stack==1)
	{
		if(array[arraySize+1] == 0)
		{
			ret = -1;
		}
		
		else
		{
			ret = array[arraySize - array[arraySize+1]];
			array[arraySize - array[arraySize+1]] = -1;
			array[arraySize+1]+=-1;
		}
	}
	return ret;
}

int peek(int stack)
{
	int ret;
	if(stack==0)
	{
		if(array[arraySize]==0)
		{
			ret = -1;
		}
		
		else
		{
			ret = array[array[arraySize]-1];
			//array[array[arraySize]-1] = -1;					//updating array with -1 after popping
			//array[arraySize]+=-1;
		}
	}
	
	if(stack==1)
	{
		if(array[arraySize+1] == 0)
		{
			ret = -1;
		}
		
		else
		{
			ret = array[arraySize - array[arraySize+1]];
			//array[arraySize - array[arraySize+1]] = -1;
			//array[arraySize+1]+=-1;
		}
	}
	return ret;

}
int isEmpty(int stack)
{	int ret;
	if(stack==0)
	{
		if(array[arraySize] == 0) ret = 1;
		else ret = 0;
	}
	
	if(stack==1)
	{
		if(array[arraySize+1] == 0) ret = 1;
		else ret = 0;
	}
	return ret;

}

int main(void)
{
        int N;
        int i,j;

        int op, val, stack;

        int status;


        scanf("%d",&N);
        init(N);

        while(scanf("%d %d",&op,&stack) != EOF){
                //printf("op = %s stack = %d\n",opNames[op],stack);
                switch(op){
                        case 0: scanf("%d",&val);status=push(stack,val); printf("%d\n",status);break;
                        case 1: status=pop(stack); printf("%d\n",status);break;
                        case 2: status=peek(stack); printf("%d\n",status);break;
                        case 3: status=isEmpty(stack);printf("%d\n",status);break;break;
                }
                for(j=0; j<N+2; j++)
				{
					printf("%i\t",array[j]);
				}
        }      
        cleanup();
        return 0;
}
