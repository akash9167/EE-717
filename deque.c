#include<stdio.h>
#include<stdlib.h>

int *array = NULL;
int head, tail, total=0;
int arraySize=0;

char opNames[7][12] = {"push_back","push_front","pop_back","pop_front","back","front","isEmpty"};

void init(int num)
{
	//total = 1;
	int i;
	arraySize = num;
    array = malloc(num*sizeof(int));
    for(i=0; i<arraySize; i++) array[i]=-1;
    head = -1;
    tail = -1;
}

void cleanup()
{
	free(array);
}

int push_back(int val)
{
	int ret;
	if(tail==arraySize-1) ret = 0;
	else
	{
		//if(tail == 0) array[tail] = val;
		array[tail+1]=val;
		tail=tail+1;
		ret = 1;
		total=total+1;
	}
	return ret;
}

int push_front(int val)
{
	int ret,j;
    if(tail==arraySize) ret = 0;
    else if(tail>=0)
    {
    	for(j=tail; j>=0; j--)
    	{
    		array[j+1]=array[j];
    		
		}
		
		array[head+1]=val;
		tail=tail+1;
		total=total+1;
		ret = 1;
	}
	else if(tail==-1)		//if first command is push front
	{
		array[0]=val;
		tail = tail+1;
		total=total+1;
		ret = 1;
	}
	return ret;
}

int pop_back()
{
	int ret;
	if(tail<0) ret = -1;

	else if(tail==0)
	{
		ret = array[tail];
    	array[tail] = -1;
    	tail = tail-1;
    	total = 0;
	}
	
	else
	{
		ret = array[tail];
    	array[tail] = -1;
    	tail = tail-1;
    	total = total-1;
	}
	
    return ret;
}
int pop_front()
{
	int ret, j;
	
	if(tail<0) ret =-1;
	else if(tail == 0)
	{
		ret = array[head+1];
		tail=-1;
		total=0;
	}
	
	else 
	{
		ret = array[head+1];
		for(j=0; j<=tail; j++)
    	{
   			array[j]=array[j+1];
		}
		tail=tail-1;
		total=total-1;
	}
	
	return ret;
}

int back()
{
	int ret = -1;
	if(tail>=0)
    	ret = array[tail];
    return ret;
}

int front()
{
	return array[head+1];
}

int isEmpty()
{
	int ret;
	
	if(tail==-1) ret = 1;
	
	else ret = 0;
	
	return ret;
}
void displayQueue()
{
    int i;
    
    printf("Deque: ");
    for(i=0; i<total; i++){
        printf("%d ",array[(head+i+1)%arraySize]);
    }
    printf("\n");
}

int main(void)
{
        int N;

        int op, val;

        int status;


        scanf("%d",&N);
        init(N);

        while(scanf("%d",&op) != EOF){
                //printf("op = %s\n",opNames[op]);
                switch(op){
                        case 0: scanf("%d",&val);status=push_back(val); printf("%d\n",status);break;
                        case 1: scanf("%d",&val);status=push_front(val); printf("%d\n",status);break;
                        case 2: status=pop_back(); printf("%d\n",status);break;
                        case 3: status=pop_front(); printf("%d\n",status);break;
                        case 4: status=back(); printf("%d\n",status);break;
                        case 5: status=front(); printf("%d\n",status);break;
                        case 6: status=isEmpty();printf("%d\n",status);break;
                        case 7: displayQueue(); break;
                }
                displayQueue();
        }       
        displayQueue();
        cleanup();
        return 0;
}
