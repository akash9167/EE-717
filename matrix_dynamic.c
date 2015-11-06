#include<stdlib.h>
#include<stdio.h>

unsigned long **k_mat;
int *divisions;
int n;
int count = 0;

struct node
{
	char data;
	struct node *next,*prev;
};
struct node *p,*q,*r,*t,*head=NULL;

////////////////////////////////////////////////////////////////////////////////////////////////
void create(char value)
{
	p=(struct node*)malloc(sizeof(struct node));
	p->data=value;
	p->next=NULL;
	p->prev=NULL;
	
	if(head==NULL)
	{
		head=p;
	}
	else
	{
		q=(struct node*)malloc(sizeof(struct node));	
		q=head;
		while(q->next!=NULL)
			q=q->next;
			
		q->next=p;
		p->prev=q;
	}
	
}

void Display()
{
	t=(struct node*)malloc(sizeof(struct node));	
	t=head;
	int count=1;
	while(t!=NULL)
	{
		if(t->data=='(' || t->data==')')
			printf("%c",t->data);
		else
		{
			printf("A%d",count++);
		}
		t=t->next;
	}
	printf("\n");
			
}

void allot(int position)
{
	p=(struct node*)malloc(sizeof(struct node));
	p=head;
	int count=0;
	
	while(count != position-1)
	{
		if(p->data=='0')
			count++;
		p=p->next;
			
	}
	while(p->next->data != '0')
	{
		p=p->next;
	}
	//cout<<"\np->data="<<p->data;
	//cout<<"\np->next->next->data="<<p->next->next->data;
		
	if(p->data=='(')		//when it is to be seperated by only one number
	{
		
		p=p->next;
		q=(struct node*)malloc(sizeof(struct node));	
		q->data='(';
		q->next=p->next;
		q->prev=p;
		p->next=q;
		q->next->prev=q;
		
		while(p->next->data!=')')
			p=p->next;
		
		q=(struct node*)malloc(sizeof(struct node));	
		q->data=')';
		q->next=p->next;
		q->prev=p;
		p->next=q;
		q->next->prev=q;
		//Display();
	
	}
	else if(p->next->next->data==')')
	{
		
		q=(struct node*)malloc(sizeof(struct node));	
		q->data=')';
		q->next=p->next;
		q->prev=p;
		p->next=q;
		q->next->prev=q;
		
		while(p->prev->data!='(')
			p=p->prev;
		
		q=(struct node*)malloc(sizeof(struct node));	
		q->data='(';
		q->next=p;
		q->prev=p->prev;
		p->prev=q;
		q->prev->next=q;
		//Display();
	}
	else
	{
		q=(struct node*)malloc(sizeof(struct node));	
		q->data='(';
		q->next=p->next;
		q->prev=p;
		p->next=q;
		q->next->prev=q;
		
		//Display();
		
		q=(struct node*)malloc(sizeof(struct node));	
		q->data=')';
		q->next=p->next;
		q->prev=p;
		p->next=q;
		q->next->prev=q;
			
		//Display();
			
		while(p->prev->data!='(')
			p=p->prev;
			
		r=(struct node*)malloc(sizeof(struct node));	
		r->data='(';
		r->next=p;
		r->prev=p->prev;
		p->prev=r;
		r->prev->next=r;
		
		//Display();
		
		while(q->next->data!=')')
			q=q->next;
		
		r=(struct node*)malloc(sizeof(struct node));	
		r->data=')';
		r->next=q->next;
		r->prev=q;
		q->next=r;
		r->next->prev=r;
		
		//Display();
			
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////



void print(int i, int j)									//creates a matrix of numbers after which division should be done
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
		//printf("\nCondition: j==i+1 || i==j-1\n");
		return;
	}
	
	else if( k==i)
	{
		//printf("\nCondition: k==i\n");
		//printf("K IS: %d\n",k);
		
		divisions[count]=k;
		
		count++;
		print(k+1,j);
	}
	
	else if( k==n)
	{
		k=k-1;
		//printf("\nCondition: k==n\n");
		//printf("K IS: %d\n",k);
		
		divisions[count]=k;
		count++;
		print(i,k);
	}
	
	else if(k>i&&k<j)
	{
		//printf("\nCondition: k>i && k<j\n");
		//printf("K IS: %d\n",k);
		
		divisions[count]=k;
		count++;
		print(i,k);
		print(k+1,j);
	}
	
	
}

int main()
{
	int l, i, j, k, work;
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
			store[i][j]=999999999;
			//printf("YO_after making value infinite\n");
			for(k=i; k<j; k++)
			{
				
				q = store[i][k]+store[(k+1)][j]+sizes[i-1]*sizes[k]*sizes[j];
				
				//printf("\nsizes[j] is: %d\n",sizes[j]);
				//printf("Before\nQ: %d\n",q);
				//printf("before Store[%d][%d]: %d\n",i,k,store[i][k]);
				//printf("before Store[%d][%d]: %d\n",k+1,j,store[k+1][j]);
				
				if(q<store[i][j]) 				
				{
					store[i][j]=q;					//storing q values for use in next iterations
					k_mat[i][j]=k;					//storing k values
					work=store[i][j];
					//printf("k_mat[%d][%d]: %d\n",i,j,k_mat[i][j]);
					//printf("after Store[%d][%d]: %d\n",i,j,store[i][j]);
				}			
			}
		}
	}
	
	print(1,n);
	
	/*for(i=0; divisions[i]!=0 && i<=n; i++)
	{
		printf("\nDivisions at: %d\n",divisions[i]);
	}
	printf("\ncount is: %d\n",count);
	*/
	////////////////////////////////////////////////////////////////////////////////////////
	printf("%d\n",work);
	create('(');
	for(i=1;i<=n;i++)
		create('0');
		
	create(')');
	
	for(i=0;i<count;i++)
		allot(divisions[i]);
	
	Display();
	//////////////////////////////////////////////////////////////////////////////////////
	//printf("\n");
	/*for(i=0; i<=n; i++)
	{
		free(store[i]);
		free(k_mat[i]);
	}
	free(divisions);
	free(store);
	free(k_mat);
	free(sizes);*/
	return 0;
}
