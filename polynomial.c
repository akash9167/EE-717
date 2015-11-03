#include<stdio.h>
/* function to calculate power x^y */
int power(int x, int y){
  int pow=1;
  while (y!=0){
      pow*=x;
      y--;
    }
  return pow;
}
int main()
{
  	int a,b,i,j;
  	int sum=0;
	scanf("%i",&a);
	if(a<1 || a>10)
	{
		main();
	}
	scanf("%i",&b);
	if(b<1 || b>10)
	{
		main();
	}
  
  	int coeff[a+1];
  	
  	for(i = 0;i <= a; i++)
    {
      	scanf("%i",&coeff[i]);
      	if(coeff[i]<0 || coeff[i]>10)
      	{
		main();
	}
    }
  
  	for(j = 0;j <= a; j++)
    {
      	sum = sum + coeff[j]*power(b,a-j);
    }
  	printf("%i",sum);
  	return 0;
}
