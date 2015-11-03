#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int *acc = NULL;
int acc_max = 0;
int b_len=0;
int a_len=1;

void init(int num)
{
	int i;
	acc_max = num;
	acc = malloc(num*sizeof(int));
	for(i=0; i<num; i++)
	{
		acc[i]=0;
	}
	acc[0]=12;
	acc[1]=14;
}

void free_mem()
{
	free(acc);
}

void add(int *a)
{
	int i, tmp;
	
	//printf("Max is: %d\n",b_len);						//a_len is acc length; b_len is b len
	
	for(i=2; i<b_len+2 || acc[i]>9; i++)
	{
		//printf("\nAcc before add is: %d ",acc[i]);
		
		tmp=acc[i]+a[i];
		
		//printf("\nA is: %d ",a[i]);
		//printf("\nTmp is: %d ",tmp);
		
		if(tmp>9) 
		{
			tmp=tmp%10;
			acc[i+1]++;
		}
		acc[i]=tmp;
	}
	
	/*if(a_len<i-2) a_len=i-2;			
	
	if(acc[i]!=0) 
	{										//first digit
		a_len=a_len+1;
	}*/
	
}

void sub(int *a)
{
	int i,tmp,small;
	

	
	for(i=2; i<b_len+2 || tmp<small; i++)
	{
	//	printf("\nA is: %d ",a[i]);
	//	printf("\nA[i+1] is: %d ",a[i+1]);
	//	printf("\nAcc is: %d ",acc[i]);
		if(a[1]==13)
		{
			tmp=a[i]-acc[i];
			small = acc[i];
			

			if(tmp<0)
			{
				tmp=tmp+10;
				a[i+1]--;
			}
			
		}
		
		else
		{
			tmp=acc[i]-a[i];
			small=a[i];
		//	printf("\nTmp before borrow is: %d ",tmp);
			if(tmp<0)
			{
				tmp=tmp+10;
				acc[i+1]--;
			}
		//	printf("\nTmp after borrow is: %d ",tmp);
		//	printf("\nA[i+1] after borrow is: %d ",a[i+1]);
		}
		acc[i]=tmp;	
	//	printf("\nAcc is: %d ",acc[i]);
	}
	
	//printf("\nlength is: %d ",i-2);
	/*a_len=i-2;			
	
	if(acc[i]!=0) 
	{											//first digit
		a_len=a_len+1;
	}*/
}

void Addition()
{
	int i;
	char *s;
	
	//for(i=1; acc[i]!=10; i++) len_acc++;

	s = malloc(101);
  	scanf("%101s", s);
  	
  	int len=strlen(s);
  	
  	if(s[0]=='-') len=len-1;
  	
  	int *b = (int *)malloc(acc_max*(sizeof(int)));
  	
  	for(i=0; i<len+2; i++) b[i] = 0;			//initializing b with 0s  
  	
  	b[1] = 14;									//14 at b[1] indicates abs(b) is smaller than abs(acc)
  	//printf("%dlength: \n",len);
	if(s[0]=='-')
	{
		b[0]=11;								//11 at b[0] indicates -ve number
		for(i=0; i<len; i++)					//creating array from string
		{
			b[i+2] = s[len-i]-'0';
			//printf("%d \n",b[i+2]);
		}
	}
	
	else
	{
		b[0]=12;								//12 at b[0] indicates +ve number
		for(i=0; i<len; i++)					//creating array from string
		{
			b[i+2] = s[len-i-1]-'0';
			//printf("%d \n",b[i+2]);
		}
	}
	
	b_len=len;									//initializing global variables
	//a_len=len_acc;					
	//printf("\nfirst element of acc%d\n",acc[a_len+1]);
	//printf("\nfirst element of b%d\n",b[len+1]);
	if(b[0]==11 && acc[0]==12)					//case 1: b -ve and acc +ve
  	{
  		if(a_len>=len&&acc[a_len+1]>b[len+1]) 							//acc >b
		{
			//printf("\nAcc greater than B\n");
			sub(b);
			acc[0]=12;
		}
		
		else 
  		{
  		//	printf("\nB greater than Acc\n");
  			b[1] = 13;							//13 at b[1] indicates abs(b) is greater than abs(acc)
  			sub(b);
  			acc[0]=11;
		}
	}
	
	
		
	else if(b[0]==12 && acc[0]==11)				//case 2: b +ve and acc -ve
  	{
  		if(a_len>=len&&acc[a_len+1]>b[len+1]) 
  		{
  			//printf("\nAcc greater than B\n");
  			sub(b);
  			acc[0]=11;
		}
		
		else
		{
			//printf("\nB greater than Acc\n");
			b[1] = 13;
			sub(b);
			acc[0]=12;
		}
	}
	
	else if(b[0]==11 && acc[0]==11)					//case 3: both -ve
  	{
		add(b);
		acc[0]=11;
	}
	
	else if(b[0]==12 && acc[0]==12)					//case 4: both +ve
  	{
		add(b);
		acc[0]=12;
	}
	
	int len_acc=0;
	int count=0;
	if(acc[0]==11) printf("-");
	//printf("\nAcc length is: %d ",len_acc);
	for(i=acc_max-1; acc[i]==0; i--) count++;
	
	len_acc = acc_max-count;
	
	count = 0;
	for(i=2; i<len_acc; i++) 
	{
		printf("%d",acc[len_acc+1-i]);
		count ++;
	}
	
	a_len=count;
	printf("\n");
	//printf("\n%d",len_acc);
}


void Subtraction()
{
	int i;
	char *s;
	
	//for(i=1; acc[i]!=10; i++) len_acc++;

	s = malloc(101);
  	scanf("%101s", s);
  	
  	int len=strlen(s);
  	
  	if(s[0]=='-') len=len-1;
  	
  	int *b = (int *)malloc(acc_max*(sizeof(int)));
  	
  	for(i=0; i<len+2; i++) b[i] = 0;			//initializing b with 0s  
  	
  	b[1] = 14;									//14 at b[1] indicates abs(b) is smaller than abs(acc)
  	//printf("%dlength: \n",len);
	if(s[0]=='-')
	{
		b[0]=11;								//11 at b[0] indicates -ve number
		for(i=0; i<len; i++)					//creating array from string
		{
			b[i+2] = s[len-i]-'0';
			//printf("%d \n",b[i+2]);
		}
	}
	
	else
	{
		b[0]=12;								//12 at b[0] indicates +ve number
		for(i=0; i<len; i++)					//creating array from string
		{
			b[i+2] = s[len-i-1]-'0';
			//printf("%d \n",b[i+2]);
		}
	}
	
	b_len=len;									//initializing global variables
	//a_len=len_acc;
	//printf("\nfirst element of acc%d\n",acc[a_len+1]);
	//printf("\nfirst element of b%d\n",b[len+1]);
	if(b[0]==11 && acc[0]==12)					//case 1: b -ve and acc +ve
  	{
  		add(b);
		acc[0]=12;
  		
	}
	
	
		
	else if(b[0]==12 && acc[0]==11)				//case 2: b +ve and acc -ve
  	{
  		add(b);
		acc[0]=11;
  		
	}
	
	else if(b[0]==11 && acc[0]==11)				//case 3: both -ve
  	{
		if(a_len>=len&&acc[a_len+1]>b[len+1]) 
  		{
  			//printf("\nAcc greater than B\n");
  			sub(b);
  			acc[0]=12;
		}
		
		else
		{
			//printf("\nB greater than Acc\n");
			b[1] = 13;
			sub(b);
			acc[0]=11;
		}
	}
	
	else if(b[0]==12 && acc[0]==12)					//case 4: both +ve
  	{
		if(a_len>=len&&acc[a_len+1]>b[len+1]) 								//acc >b
		{
			//printf("\nAcc greater than B\n");
			sub(b);
			acc[0]=12;
		}
		
		else 
  		{
  			//printf("\nB greater than Acc\n");
  			b[1] = 13;								//13 at b[1] indicates abs(b) is greater than abs(acc)
  			sub(b);
  			acc[0]=11;
		}
	}
	int len_acc=0;
	int count=0;
	if(acc[0]==11) printf("-");
	//printf("\nAcc length is: %d ",len_acc);
	for(i=acc_max-1; acc[i]==0; i--) count++;
	
	len_acc = acc_max-count;
	count = 0;
	for(i=2; i<len_acc; i++) 
	{
		printf("%d",acc[len_acc+1-i]);
		count ++;
	}
	
	a_len=count;
	
	printf("\n");
	//printf("\n%d",len_acc);
	
}

int main()
{
	int num = 1000;
	int j, opp, k=0;
	
	init(num);						//initializing acc
	
	scanf("%d",&j);
	
	while(k<j)						//operations
  	{
  		scanf("%d",&opp);
  		if(opp==0) Addition();
  		else if(opp==1) Subtraction();
  		k++;
	}
	
	free_mem();
}
