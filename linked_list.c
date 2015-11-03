#include <stdio.h>
#include<stdlib.h>

struct node {
    int val;
    struct node *next;
};

typedef struct node * nodePtr;

char operations[][30] = {"add","deleteFirstOccurence","deDuplicate","reverseList","isSorted","getLength","printList"};

nodePtr head;

void init(void)
{
    head = (nodePtr) malloc (sizeof(struct node));
    head->val = 0;
    head->next = NULL;
}

void cleanup(void)
{
    if (head==NULL) return;
    nodePtr curr=head->next, tmp;

    while(curr!=NULL){
       tmp = curr->next;
       free(curr);
       curr = tmp;
    }
    head->val = 0;
    head->next = NULL;
}

void printList(void)
{
    printf("List: ");
    if(head == NULL || head->val == 0){
        printf("\n");
        return;
    }
    nodePtr tmp = head->next;
    while(tmp!=NULL){
        printf("%d ",tmp->val);
        tmp=tmp->next;
    }
    printf("\n");
}

void printListWithPointers(void)
{
    if(head==NULL){
        printf("List header not created\n");
        return;
    }
    printf("(Head, %p) -> ",head->next);
    if(head->val == 0){
        printf("NULL\n");
        return;
    }
    else{
        nodePtr tmp = head->next;
        while(tmp->next != NULL){
            printf("(%d %p) -> ",tmp->val,tmp->next);
            tmp=tmp->next;
        }
        printf("(%d %p)",tmp->val,tmp->next);
        
        printf("\n");
    }
}

int add(int val)
{
	struct node *new_node = (struct node*)malloc(sizeof(struct node)) ;
	struct node *tmp = (struct node*)malloc(sizeof(struct node)) ;
	
	if(new_node == NULL || tmp== NULL)
	{
		return 0;
	}
	
	else
	{
		new_node->val = val;
		new_node->next = NULL;
		
		tmp = head;
		
		while(tmp!=NULL)
		{
			tmp = tmp->next;
		}
		
		tmp->next = new_node;
	}
}


int getLength()
{
	//write your code here
}

int deleteFirstOccurence(int val)
{
	//write your code here
}

int deDuplicate(void)
{
	//write your code here
}

void reverseList(void)
{
	//write your code here
}

int isSorted(nodePtr p)
{
	//write your code here
}

int main(void)
{
    int op, val;

    int status;


    init();

    while(scanf("%d",&op) != EOF){
        switch(op){
            case 0: scanf("%d",&val);status=add(val); printf("%d\n",status);break;
            case 1: scanf("%d",&val);status=deleteFirstOccurence(val); 
                        printf("%d\n",status);break;
            case 2: status=deDuplicate(); printf("%d\n",status);break;
            case 3: reverseList(); break;
            case 4: status=isSorted(head->next); printf("%d\n",status);break;
            case 5: status=getLength(head); printf("%d\n",status);break;
            case 6: printList(); break;
        }   
    }           
    
    printList();
    cleanup();
    return 0;
}

