#include<stdio.h>
int main(void)
{
	int n,sum;
	scanf(" %i",&n);

	if(n>=1 && n<=10000000)
    {  
		if(n/10==0)					//Single digit number
    	{sum=n;}
		else
  			while(n/10!=0)			//
    		{
    	    	sum=0;
    	  		while(n>0)
    			{
    			    sum += n%10;
    	   		    n = n/10;
    			}
    			n=sum;
    		}

    	printf("%i",sum);
    	return 0;
    }
	else(main());
}
