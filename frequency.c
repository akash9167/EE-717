#include<stdio.h>
int main(){
	int n,count,max,i,a,j,mode,first; 
	max = -1;

    scanf("%i",&n);
	
	if(n < 1 || n > 10000) 
	{
		
      printf("wrong array size\n");
      main();
    };
	
    int series[n];
    first = 101;
    while(1)
    {
    	scanf("%i",&first);
    	if(first >= -100 && first <= 100 )		//checking first element 
      	{
          	series[0]=first;
          	break;
        };
	}

    for(a=1; a<n; a++)
    {
        scanf("%i",&series[a]);					// checking remaining
      	if(series[a] < -100 || series[a] > 100) 	
      	{
          a=a-1;
        };
        
    }
	//counting numbe rof times a number appears after its first occurence
    for(i=0; i<n-1; i++)
    {
      	count = 0;
        for(j=i+1; j<n; j++)
        {
            if(series[i]==series[j])
            {
                count = count + 1;
            }
        }
      
        if(count > max)
        {
            max = count;
            mode = series[i];
        }
    }

	printf("%i",mode);
    
} 
    
