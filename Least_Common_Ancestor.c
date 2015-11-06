#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node
{
	char data;
	struct node *left,*right,*top;
}*p,*q,*r,*t,*head=NULL;

int mat[100];

void create(char value)
{
	p=(struct node*)malloc(sizeof(struct node));
	p->data=value;
	p->left=NULL;
	p->right=NULL;
	p->top=NULL;
	if(head==NULL)
	{
		head=p;
	}
	
	else
	{
		q=(struct node*)malloc(sizeof(struct node));	
		q=head;
		
		while(true)	
		{	
			if(q->data > p->data)
			{
				//printf("Element smaller than prev\n");
				if(q->left!=NULL) q=q->left;
				else
				{
					q->left=p;
					p->top=q;
					break;
				}
			}
			else if(q->data < p->data)
			{
				//printf("Element greater than prev\n");
				if(q->right!=NULL) q=q->right;
				else
				{
					q->right=p;
					p->top=q;
					break;
				}
			}
		}
	}
}

void lca(char value1, char value2)											//LCA
{
	char ancestor='0';
	p=(struct node*)malloc(sizeof(struct node));
	p=head;
	
	q=(struct node*)malloc(sizeof(struct node));
	q=head;
	
	r=(struct node*)malloc(sizeof(struct node));
	r=head;
	
	while(p->data!=value1)							//finding value1
	{	
		if(value1 < p->data)
		{
			//printf("Element1 smaller than prev\n");
			p=p->left;
		}
		else if(value1 > p->data)
		{
			//printf("Element1 greater than prev\n");
			p=p->right;
		}
	}
	//printf("\nidentified position p\n");
	while(q->data!=value2)							//finding value 2
	{	
		//printf("\nFinding value 2\n");
		if(value2 < q->data)
		{
			//printf("Element2 smaller than prev\n");
			q=q->left;
		}
		else if(value2 > q->data)
		{
			//printf("Element2 greater than prev\n");
			q=q->right;
		}
	}
	//printf("\nidentified position q\n");
	
	while(r->left!=0 ||r->right!=0)					//finding LCA
	{
		if(r->data==q->data || r->data==p->data) 
		{
			ancestor=r->data;
			break;
		}
		
		else if(r->data > p->data && r->data > q->data) r=r->left;
		
		else if(r->data < p->data && r->data < q->data) r=r->right;
		
		else if(r->data < p->data && r->data > q->data)
		{
			ancestor=r->data;
			break;
		}
		
		else if(r->data > p->data && r->data < q->data)
		{
			ancestor=r->data;
			break;
		}
		else printf("\nFuckers were not found\n");
	}

	printf("%c\n",ancestor);
}

void preorder(struct node *a)											//PREORDER
{
	char curr='0';
	//a=(struct node*)malloc(sizeof(struct node));
	//a=head;
	printf("%c",a->data);
	if(a->left!=0)
	{
		preorder(a->left);
	}
	
	if(a->right!=0)
	{
		preorder(a->right);
		return;
	}
	
	if(a->right==0&&a->left==0) return;
}

void inorder(struct node *a)										//INORDER
{
	char curr='0';
	//a=(struct node*)malloc(sizeof(struct node));
	//a=head;
	//printf("%c\t",a->data);
	if(a->left!=0) inorder(a->left);

	if(a->right==0&&a->left==0)
	{
		printf("%c",a->data);
		return;
	}
	
	printf("%c",a->data);
	
	if(a->right!=0)
	{
		inorder(a->right);
	}
	
	else return;
}

int main()
{
	int length, op, i;
	char element, value1, value2;
	float n = 1;
	
	scanf("%d",&length);
	
	for(i=0; i<length; i++) n=2.0*n;
	
	for(i=1; i<=length; i++)
	{	
		scanf(" %c",&element);
		create(element);
	}
	
	scanf("%d",&op);
	
	for(i=0; i<op; i++)
	{
		scanf(" %c",&value1);
		scanf(" %c",&value2);
		lca(value1, value2);
		
		printf("(");
		preorder(r);
		printf(")(");
		inorder(r);
		printf(")\n");
	}
	
}
